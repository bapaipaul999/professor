class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>temp;
        for(int i = 0 ; i<bank.size() ; i++){
            int count = 0;
            for(auto it : bank[i]){
                if(it == '1'){
                    count ++ ;
                }
            }
            if(count !=0){
                temp.push_back(count);
            }
        }
        if(temp.size() <2){
            return 0;
        }
        int sum = 0;
        for(int i = 0 ; i<temp.size()-1 ; i++){
            sum = sum + temp[i]*temp[i+1];
        }
        return sum;
    }
};