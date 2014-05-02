class Solution {
public:
    void reverseWords(string &s) {
        string result = "";
        vector<string> words;
        bool isInaword = false;
        string word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(isInaword){
                    isInaword = false;
                    word += s[i];
                    words.push_back(word);
                    word = "";
                }
            }
            else{
                if(!isInaword)
                    isInaword = true;
                word += s[i];
            }
        }
        if(isInaword){
			words.push_back(word + " ");
		}
        for(int i = words.size() - 1;i > -1; i--){
            result += words[i];
        }
        s = result.substr(0, result.size() - 1);
    }
};
