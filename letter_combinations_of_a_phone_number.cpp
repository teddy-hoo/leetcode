/**
 * breadth first search algorithm
 * time:   O(3^n)
 * space:  O(3^n)
 * date:   25-01-2015
 * author: Teddy
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        int len = digits.size();
        vector<string> results;
        results.push_back("");
        
        if(len <= 0){
            return results;
        }
        
        // the characters on each phone number
        string characters[8] = {"abc", "def", "ghi", "jkl", 
                                "mno", "pqrs", "tuv", "wxyz"};
        
        for(int i = 0; i < len; i++){
            string chars = characters[digits[i] - '2'];
            int before = results.size();
            vector<string> newResults;
            for(int j = 0; j < chars.size(); j++){
                for(int k = 0; k < before; k++){
                    newResults.push_back(results[k] + chars[j]);
                }
            }
            results = newResults;
        }
        return results;
    }
};
