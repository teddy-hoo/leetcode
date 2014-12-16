class Solution {
public:
    int sqrt(int x) {
        if(x <= 1){
            return x;
        }
        
        int left = 1;
        int right = x / 2;
        
        while(left <= right){
            int mid = left + ((right - left)>>1);
            if(mid == x / mid)
            {
                return mid;
            }
            else if(mid < x / mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return right;
    }
};
