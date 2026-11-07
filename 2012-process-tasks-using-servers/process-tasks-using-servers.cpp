class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available servers: {weight, index}
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        // Busy servers: {freeTime, weight, index}
        using T = tuple<long long,int,int>;

        priority_queue<T, vector<T>, greater<T>> busy;

        vector<int> ans;

        for (int i = 0; i < servers.size(); i++) {
            available.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

            // Release servers that have finished
            while (!busy.empty() &&
                   get<0>(busy.top()) <= time) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if (available.empty()) {

                time = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // Mark server as busy
            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};