class Solution {
private:
    unordered_map<int, int> countNumbers(int A[], int n){
        unordered_map<int, int> count;
        
        for(int i = 0; i < n; i++){
            if(count.find(A[i]) == count.end()){
                count[A[i]] = 1;
            }
            else{
                count[A[i]]++;
            }
        }
        
        return count;
    }
public:
    int singleNumber(int A[], int n) {
        
        if(n <= 0){
            return -1;
        }
        
        unordered_map<int, int> count = countNumbers(A, n);
        
        for(unordered_map<int, int>::iterator iter = count.begin(); iter != count.end(); iter++){
            if(iter->second == 1){
                return iter->first;
            }
        }
        
        return -1;
    }
};