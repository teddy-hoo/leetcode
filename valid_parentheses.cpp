/**
 * depth first search algorithm
 * time:   O(n)
 * space:  O(n)
 * date:   25-01-2015
 * author: Teddy
 */

#define LEFT_PARENTHESES '('
#define RIGHT_PARENTHESES ')'
#define LEFT_SQUARE '['
#define RIGTH_SQUARE ']'
#define LEFT_BRACE '{'
#define RIGTH_BRACE '}'

class Solution {
private:
    bool validation(stack<char> &parentheses, char cur){
        if(cur == RIGHT_PARENTHESES){
            if(!parentheses.empty() &&
                parentheses.top() == LEFT_PARENTHESES){
                parentheses.pop();
            }
            else{
                return false;
            }
        }
        else if(cur == RIGTH_SQUARE){
            if(!parentheses.empty() && 
                parentheses.top() == LEFT_SQUARE){
                parentheses.pop();
            }
            else{
                return false;
            }
        }
        else if(cur == RIGTH_BRACE){
            if(!parentheses.empty() &&
                parentheses.top() == LEFT_BRACE){
                parentheses.pop();
            }
            else{
                return false;
            }
        }

        return true;
    }
public:
    bool isValid(string s) {
        stack<char> parentheses;
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == LEFT_PARENTHESES ||
               s[i] == LEFT_SQUARE ||
               s[i] == LEFT_BRACE){
                parentheses.push(s[i]);
                continue;
            }

            if(!validation(parentheses, s[i])){
                return false;
            }
        }

        if(parentheses.empty()){
            return true;
        }
        
        return false;
    }
};
