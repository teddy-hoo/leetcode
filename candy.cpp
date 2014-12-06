class Solution {
public:
    int candy(vector<int> &ratings) {
        int  size = ratings.size();
        int* candy = new int[size];
        fill(candy , candy + size , 0);
         
        int k = 1;
        for(int i = 1 ; i < size ; i++){
            if(ratings[i] > ratings[i - 1]){
                candy[i] = k++;
            }else{
                k = 1;
            }
        }
        k = 1;
        for(int i = size -2 ; i >= 0 ; i --){
            if(ratings[i] > ratings[i + 1]){
                candy[i] = max(k++ , candy[i]);
            }else{
                k = 1;
            }
        }
        int ans = size;
        for(int i = 0 ; i < size ; i++) ans += candy[i];
         
        return ans;
    }
};
