class Solution {
public:
    string countAndSay(int n) {
        if(n == 0){
            return "";
        }
        string current = "1";
        for(int i = 1; i < n; i++){
            string next = "";
            char cur = current[0];
            int count = 1;
            for(int j = 1; j <= current.size(); j++){
                if(j >= current.size() || current[j] != current[j - 1]){
                    stringstream ss;
                    ss << count;
                    next += ss.str();
                    next += current[j - 1];
                    count = 1;
                }
                else{
                    count++;
                }
            }
            current = next;
        }
        return current;
    }
};
