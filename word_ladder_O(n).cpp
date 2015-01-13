class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        queue<string> q;
        q.push(start);

        map<string, int> dis;
        dis[start] = 1;

        while(!q.empty()){
            string str = q.front();
            q.pop();
            if(str == end){
                break;
            }
            for(int i = 0; i < str.size(); i++){
                string tmp = str;
                for(char j = 'a'; j <= 'z'; j++){
                    tmp[i] = j;
                    if(dict.count(tmp) > 0 && dis.count(tmp) == 0){
                        dis[tmp] = dis[str] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
        return dis.count(end) == 0 ? 0 : dis[end];
    }
};