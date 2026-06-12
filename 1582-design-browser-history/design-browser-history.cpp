class BrowserHistory {
public:
    vector<string>ans;
    int i = 0;
    BrowserHistory(string homepage) {
        ans.push_back(homepage);
    }
    
    void visit(string url) {
        if(ans.size()-1==i){
            ans.push_back(url);
            i++;
        }
        else{
            ans.erase(ans.begin()+i+1,ans.end());
            ans.push_back(url);
            i++;
        }
    }
    
    string back(int steps) {
        
        i = max(0, i - steps);
        return ans[i];
    }
    
    string forward(int steps) {
        i = min((int)ans.size()-1, i + steps);
        return ans[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */