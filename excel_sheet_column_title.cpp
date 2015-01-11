class Solution {
public:
    string convertToTitle(int n) {
        
        string result;
        
        while(n > 0){
            int cur = n % 26;
            result.insert(result.begin(), cur == 0 ? 'Z' : cur + 'A' - 1);
            n = n / 26;
            n = cur == 0 ? n - 1 : n;
        }
        
        return result;
                
    }
};
