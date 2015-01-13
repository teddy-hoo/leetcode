class Solution {
private:
    void fillChars(string t, map<char, int> &chars){
        map<char, int>::iterator iter;
        for(int i = 0; i < t.size(); i++){
            iter = chars.find(t[i]);
            if(iter == chars.end()){
                chars[t[i]] = 1;
            }
            else{
                chars[t[i]]++;
            }
        }
    }
public:
    string minWindow(string S, string T) {
        int lent = T.size();
        int lens = S.size();
        
        if(lens <= 0 || lent <= 0){
            return "";
        }
        
        map<char, int> chars;
        map<char, int>::iterator iter;
        int left = 0;
        int start = 0;
        int minlen = lens + 1;
        int count = 0;

        fillChars(T, chars);
        
        for(int i = 0; i < lens; i++){
            iter = chars.find(S[i]);
            if(iter != chars.end()){
                iter->second--;
                if(iter->second >= 0){
                    count++;
                }
            }
            while(count == lent){
                iter = chars.find(S[left]);
                if(iter != chars.end()){
                    iter->second++;
                    if(iter->second > 0){
                        count--;
                        int len = i - left + 1;
                        if(minlen > len){
                            minlen = len;
                            start = left;
                        }
                    }
                }
                left++;
            }
        }
        
        return minlen <= lens ? S.substr(start, minlen) : "";
    }
};
