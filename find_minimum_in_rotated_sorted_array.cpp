class Solution {
public:
    int findMin(vector<int> &num) {
        
        int len = num.size();

        if(len <= 0){
            return -1;
        }

        int begin = 0;
        int end = len - 1;
        while(begin < end){
            int middle = (begin + end) >> 1;
            if(num[begin] <= num[middle]){
                if(num[end] < num[begin]){
                    begin = middle + 1;
                }
                else{
                    return num[begin];
                }
            }
            else{
                if(num[middle - 1] < num[middle]){
                    end = middle - 1;
                }
                else{
                    return num[middle];
                }
            }
        }

        return num[begin];
    }
};