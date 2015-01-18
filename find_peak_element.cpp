class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int len = num.size();

        if(len <= 0){
            return -1;
        }

        int begin = 0;
        int end = len - 1;
        while(begin < end){
            int middle = (begin + end) >> 1;
            int next = middle + 1;
            if(num[middle] < num[next]){
                begin = next;
            }
            else{
                end = middle;
            }
        }

        return begin;
    }
};
