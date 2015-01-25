/**
 * a simple string problem
 * time:   O(nm)
 * space:  O(0)
 * date:   25-01-2015
 * author: Teddy
 */


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        
        if(len <= 0){
            return "";
        }
        
        int length = 0;
        bool isPrefix = true;
        while(isPrefix){
            if(length >= strs[0].size()){
                break;
            }
            char p = strs[0][length];
            for(int i = 1; i < len; i++){
                if(length >= strs[i].size() || strs[i][length] != p){
                    isPrefix = false;
                    length--;
                    break;
                }
            }
            length++;
        }
        
        return length > 0 ? strs[0].substr(0, length) : "";
    }
};