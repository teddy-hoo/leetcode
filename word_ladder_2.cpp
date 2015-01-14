class Solution {
private:
    map<string, vector<string> > buildGraph(unordered_set<string> dict,
        string start, string end){

        map<string, vector<string> > graph;
        set<string> visited;
        visited.insert(start);
        visited.insert(end);

        queue<string> q;
        q.push(start);
        bool reachEnd = false;
        int next = 0;
        int cur = 1;

        while(!q.empty() && cur > 0){
            
            string str = q.front();
            q.pop();

            vector<string> neighbors;
            for(int i = 0; i < str.size(); i++){
                string tmp = str;
                for(char j = 'a'; j <= 'z'; j++){
                    tmp[i] = j;
                    if(str == tmp){
                        continue;
                    }
                    if(tmp == end){
                        reachEnd = true;
                        neighbors.push_back(tmp);
                    }
                    else if(!reachEnd && dict.count(tmp) > 0 && visited.count(tmp) == 0){
                        next++;
                        visited.insert(tmp);
                        neighbors.push_back(tmp);
                        q.push(tmp);
                    }
                }
            }
            
            cur--;
            if(cur == 0 && !reachEnd){
                cur = next;
                next = 0;
            }

            graph[str] = neighbors;
        }

        if(!reachEnd){
            graph.clear();
        }
        
        return graph;
    }
    void dfs(map<string, vector<string> > graph, vector<string> path,
        string end, vector<vector<string> > &results){
        
        string start = path.back();

        if(start == end){
            results.push_back(path);
            return;
        }
        
        map<string, vector<string> >::iterator iter;
        iter = graph.find(start);
        if(iter == graph.end()){
            return;
        }
        vector<string> neighbors = iter->second;
        for(int i = 0; i < neighbors.size(); i++){
            path.push_back(neighbors[i]);
            dfs(graph, path, end, results);
            path.pop_back();
        }
        
    }
public:
    vector<vector<string> > findLadders(string start, string end, 
      unordered_set<string> &dict) {

        vector<vector<string> > results;
        map<string, vector<string> > graph;

        graph = buildGraph(dict, start, end);

        vector<string> path;
        path.push_back(start);

        dfs(graph, path, end, results);

        return results;
    }
};
