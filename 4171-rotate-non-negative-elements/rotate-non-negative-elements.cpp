class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        set<int> s1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                s1.insert(i);
            } else {
                temp.push_back(nums[i]);
            }
        }

        if (temp.empty()) return nums;  

        k %= temp.size();              

        vector<int> temp1(temp.size());

        for (int i = 0; i < temp.size(); i++) {
    temp1[(i - k + temp.size()) % temp.size()] = temp[i];
}

        int x = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (s1.find(i) == s1.end()) {
                nums[i] = temp1[x];
                x++;
            }
        }

        return nums;
    }
};