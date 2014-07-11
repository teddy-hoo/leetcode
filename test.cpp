#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
	string s = "()";
	stack<char> stk;
        for(int i = 0; i < s.size(); ++i){
        	cout << i << endl;
        	cout << stk.size() << endl;
        	cout << s[i] << endl;
        	if(!stk.empty()){
        		cout << stk.top() << endl;
        	}
        	if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        		stk.push(s[i]);
        	}
        	else if(s[i] == ')'){
        		if(!stk.empty() && stk.top() == '('){
        			stk.pop();
        		}
        		else{
        			cout << "false )";
        		}
        	}
        	else if(s[i] == ']'){
        		if(!stk.empty() && stk.top() == '['){
        			stk.pop();
        		}
        		else{
        			cout << "false ]";
        		}
        	}
        	else if(s[i] == '}'){
        		if(!stk.empty() && stk.top() == '{'){
        			stk.pop();
        		}
        		else{
        			cout << "false }";
        		}
        	}
        }
        if(stk.empty()){
        	cout << "true";
        }
        cout << "true";
	return 1;
}