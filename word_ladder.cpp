class Solution {
private:
    bool converted(string s1, string s2){
        int identical = 0;
        int len = s1.size();
        for(int i = 0; i < len; i++){
            if(s1[i] == s2[i]){
                identical++;
            }
        }
        return identical == len - 1;
    }
    map<string, vector<string> > buildGraph(unordered_set<string> dict, map<string, bool> &visited){
        unordered_set<string>::iterator i;
        unordered_set<string>::iterator j;
        map<string, vector<string> > graph;
        
        for(i = dict.begin(); i != dict.end(); i++){
            vector<string> neighbors;
            for(j = dict.begin(); j != dict.end(); j++){
                if(*i != *j && converted(*i, *j)){
                    neighbors.push_back(*j);
                }
            }
            graph[*i] = neighbors;
            visited[*i] = false;
        }
        
        return graph;
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        dict.insert(start);
        dict.insert(end);
        
        map<string, vector<string> > graph;
        map<string, bool> visited;
        graph = buildGraph(dict, visited);
        
        queue<string> q;
        q.push(start);
        visited[start] = true;
        int step = 1;
        int cur = 1;
        int next = 0;
        while(!q.empty()){
            string str = q.front();
            q.pop();
            if(str == end){
                return step;
            }
            vector<string> neighbors = graph[str];
            for(int i = 0; i < neighbors.size(); i++){
                string s = neighbors[i];
                if(!visited[s]){
                    q.push(s);
                    visited[s] = true;
                    next++;
                }
            }
            cur--;
            if(cur == 0){
                step++;
                cur = next;
                next = 0;
            }
        }
        return -1;
    }
};