class Solution {
private:
    int targetValue;
    int *integers;
    void binarySearch(int &begin, int &end, int &targetPos){
        
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(integers[mid] == targetValue){
                targetPos = mid;
                return;
            }
            else if(integers[mid] < targetValue){
                begin = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        
    }
    int findRange(int begin, int end, bool pre){
        
        if(begin > end){
            return pre ? begin : end;
        }
        
        int targetPos = -1;
        while(1){
            binarySearch(begin, end, targetPos);
            if(targetPos == -1){
                return pre ? end + 1 : begin - 1;
            }
            if(pre){
                if(targetPos <= begin){
                    return targetPos;
                }
                else if(integers[targetPos] != integers[targetPos - 1]){
                    return targetPos;
                }
                else{
                    end = targetPos - 1;
                }
            }
            else{
                if(targetPos >= end){
                    return targetPos;
                }
                else if(integers[targetPos] != integers[targetPos + 1]){
                    return targetPos;
                }
                else{
                    begin = targetPos + 1;
                }
            }
        }
        
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> range;
        if(n <= 0){
            return range;
        }
        
        targetValue = target;
        integers = A;
        int targetPos = -1;
        int begin = 0;
        int end = n - 1;
        
        binarySearch(begin, end, targetPos);
        
        if(targetPos == -1){
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }
        
        int pre = findRange(begin, targetPos - 1, true);
        int post = findRange(targetPos + 1, end, false);
        
        range.push_back(pre);
        range.push_back(post);
        return range;
    
    }
};
