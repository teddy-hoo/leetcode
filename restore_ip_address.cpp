class Solution {
private:
    string ipString;
    void genIpAddress(int index, int parts, string &middle, vector<string> &results){
        if(index == ipString.size()){
            if(parts == 4){
                results.push_back(middle);
            }
            return;
        }
        if(parts == 4){
            return;
        }
        int begin = index;
        int val = ipString[index] - '0';
        while(val <= 255){
            string m = ipString.substr(begin, index - begin + 1);
            string next = parts == 3 ? middle + m : middle + m + ".";
            genIpAddress(index + 1, parts + 1, next, results);
            index++;
            if(index == ipString.size() || val == 0){
                return;
            }
            val = val * 10 + ipString[index] - '0';
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> results;
        ipString = s;
        int len = s.size();
        
        if(len <= 0){
            return results;
        }
        
        string e;
        
        genIpAddress(0, 0, e, results);
        
        return results;
        
    }
};