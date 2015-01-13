class Solution {
private:
    int removePre(map<int, int> &rem, int min, int count, int start, vector<bool> &used){
        map<int, int>::iterator iter;
        for(iter = rem.begin(); iter != rem.end(); iter++){
            if(iter->second <= min){
                rem.erase(iter);
                used[iter->first] = false;
                count--;
            }
            else if(iter->second < start){
                start = iter->second;
            }
        }
        return start;
    }
    int findChar(string s, vector<bool> used, char c){
        for(int i = 0; i < s.size(); i++){
            if(c == s[i] && !used[i]){
                return i;
            }
        }
        return -1;
    }
public:
    string minWindow(string S, string T) {
        int lent = T.size();
        int lens = S.size();
        
        if(lens <= 0 || lent <= 0){
            return "";
        }
        
        map<int, int> positions;
        map<int, int>::iterator iter;
        vector<bool> used(T.size(), false);
        int start = -1;
        int count = 0;
        int rs = -1;
        int min = lens + 1;
        char pre = S[0];
        
        for(int i = 0; i < lens; i++){
            char si = S[i];
            int pos = findChar(T, used, si);
            if(pos < 0){
                continue;
            }
            used[pos] = true;
            iter = positions.find(si);
            if(iter == positions.end()){
                positions[pos] = i;
                count++;
                if(start == -1) start = i;
                if(count == lent){
                    int len = i - start + 1;
                    if(len < min){
                        rs = start;
                        min = len;
                    }
                }
            }
            else{
                start = removePre(positions, iter->second, count, i, used);
                positions[si] = i;
                count++;
                if(count == lent){
                    if(i - start + 1 < min){
                        rs = start;
                        min = i - start + 1;
                    }
                }
            }
        }
        
        return rs >= 0 ? S.substr(rs, min) : "";
    }
};
