class Solution {
private:
    int findSubstring(string s, string t, int is, int it){
        int lens = s.size();
        int lent = t.size();
        
        if(is == lens){
            return it == lent ? 1 : 0;
        }
        if(it == lent){
            return 1;
        }
        
        if(lens - is < lent - it){
            return 0;
        }

        int nums = 0;
        if(s[is] == t[it]){
            nums += findSubstring(s, t, is + 1, it + 1);
        }
        nums += findSubstring(s, t, is + 1, it);
        return nums;
    }
public:
    int numDistinct(string S, string T) {
        
        if(S.size() == 0 || T.size() == 0){
            return 0;
        }

        return findSubstring(S, T, 0, 0);
    }
};