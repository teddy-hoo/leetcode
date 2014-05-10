class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> cache;
        int first;
        int second;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9'){
                cache.push(atoi(tokens[i].c_str()));
                continue;
            }
            if(tokens[i][0] == '-' && tokens[i][1] >= '0' && tokens[i][1] <= '9'){
                cache.push(atoi(tokens[i].c_str()));
                continue;
            }
            switch(tokens[i][0]){
                case '+':
                    first = cache.top();
                    cache.pop();
                    second = cache.top();
                    cache.pop();
                    cache.push(second + first);
                    break;
                case '-':
                    first = cache.top();
                    cache.pop();
                    second = cache.top();
                    cache.pop();
                    cache.push(second - first);
                    break;
                case '*':
                    first = cache.top();
                    cache.pop();
                    second = cache.top();
                    cache.pop();
                    cache.push(second * first);
                    break;
                case '/':
                    first = cache.top();
                    cache.pop();
                    second = cache.top();
                    cache.pop();
                    cache.push(second / first);
                    break;
            }
        }
        return cache.top();
    }
};
