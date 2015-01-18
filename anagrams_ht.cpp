class Solution {
private:
    void reverse(string &s){
        int len = s.size();
        int up = len / 2;
        for(int i = 0; i < up; i++){
            char tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }
    }
public:
    vector<string> anagrams(vector<string> &strs) {
        
        int len = strs.size();
        vector<string> result;

        if(len <= 0){
            return result;
        }

        unordered_set<string> cache;
        for(int i = 0; i < len; i++){
            string cur = strs[i];
            reverse(cur);
            bool finded = false;
            if(cache.count(strs[i]) > 0){
                result.push_back(strs[i]);
                finded = true;
            }
            if(cache.count(cur) > 0){
                result.push_back(cur);
                finded = true;
            }
            if(finded){
                result.push_back(strs[i]);
            }
            cache.insert(strs[i]);
        }

        return result;
    }
};