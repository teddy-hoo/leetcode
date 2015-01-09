class Solution {
private:
    string genLine(vector<string> words, int cur, int L, int begin, int end){
        string line;
        int slotCount= end - begin;
        int spaces = L - cur + slotCount;
        int slot = slotCount == 0 ? spaces : spaces / slotCount;
        int first = slotCount == 0 ? -1 : spaces % slotCount - 1;
        for(int i = begin; i <= end; i++){
            line += words[i];
            int up = i <= begin + first ? slot + 1 : slot;
            for(int j = 0; line.size() < L && j < up; j++){
                line += " ";
            }
        }
        return line;
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        
        int len = words.size();
        vector<string> result;
        
        if(len <= 0){
            return result;
        }
        
        int cur = 0;
        int begin = 0;
        for(int i = 0; i < len; i++){
            cur += words[i].size();
            if(cur > L){
                result.push_back(genLine(words, cur - 1 - words[i].size(), L, begin, i - 1));
                begin = i;
                cur = 0;
                i--;
            }
            else{
                cur++;
            }
        }
        if(begin < len){
            string line;
            line += words[begin];
            for(int i = begin + 1; i < len; i++){
                line += " ";
                line += words[i];
            }
            cur = line.size();
            while(cur < L){
                line += " ";
                cur++;
            }
            result.push_back(line);
        }
        
        return result;
    }
};