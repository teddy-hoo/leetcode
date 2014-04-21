class Solution {
public:
    int jump(int A[], int n) {
        if(n == 1)
            return 0;
        int step = 1;
        int cur_len = A[0];
        int max_len = cur_len, max_pos = cur_len;
        for(int cur = 1; cur < n;){
            if(cur == cur_len + 1){
                cur_len = max_pos + A[max_pos];
                cur = max_pos + 1;
                max_len = cur_len;
                max_pos = cur_len;
                step++;
                continue;
            }
            if(A[cur] + cur > max_len){
                max_len = A[cur] + cur;
                max_pos = cur;
            }
            cur++;
        }
        return step;
    }
};
