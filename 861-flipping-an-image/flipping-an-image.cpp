class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0 ; i < image.size();i++){
            int start = n*i;
            int end = (i+1)*n -1;
            while(start < end){
                swap(image[start/n][start%n],image[end/n][end%n]);
                start++;
                end--;
            }
        }
        for(int i = 0 ; i < image.size();i++){
            for(int j = 0; j < image.size() ; j++){
                if(image[i][j] == 0){
                    image[i][j] = 1;
                }
                else{
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
};