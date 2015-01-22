class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majority = num[0];
        int count = 0;
        int len = num.size();

        for(int i = 0; i < len; i++){
            if(count == 0){
                majority = num[i];
                count++;
            }
            else{
                majority == num[i] ? count++ : count--;
            }
        }
        return majority;
    }
};