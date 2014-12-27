class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> results;
        results.push_back("");
        if(len <= 0){
            return results;
        }
        string characters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < len; i++){
            vector<string> tmp;
            int index = digits[i] - '2';
            string curStr = characters[index];
            for(int j = 0; j < curStr.size(); j++){
                for(int k = 0; k < results.size(); k++){
                    tmp.push_back(results[k] + curStr[j]);
                }
            }
            results = tmp;
        }
        return results;
    }
};