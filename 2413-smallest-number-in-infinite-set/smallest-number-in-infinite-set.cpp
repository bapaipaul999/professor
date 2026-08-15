class SmallestInfiniteSet {
public:
    set<int>s1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(s1.empty()){
            s1.insert(1);
            return 1;
        }
        int maxi = *max_element(s1.begin(),s1.end());
        int miss = 0;
        for(int i = 1 ; i<=maxi ; i++){
            if(s1.find(i)==s1.end()){
                s1.insert(i);
                return i;
            }
        }
        s1.insert(maxi+1);
        return maxi+1;
    }
    
    void addBack(int num) {
        if(s1.find(num)!=s1.end()){
            s1.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */