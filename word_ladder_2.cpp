class Solution {
private:
    map<string, vector<string> > graph;
    vector<vector<string> > results;
    string des;
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
    map<string, vector<string> > buildGraph(unordered_set<string> dict,
        map<string, bool> &visited){
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
    void dfs(vector<string> path, int &minlen, map<string, bool> visited){
        
        string start = path.back();

        if(start == des){
            results.push_back(path);
            minlen = path.size() < minlen ? path.size() : minlen;
            return;
        }

        if(path.size() + 1 > minlen){
            return;
        }
        
        vector<string> neighbors = graph[start];
        for(int i = 0; i < neighbors.size(); i++){
            string neighbor = neighbors[i];
            if(!visited[neighbor]){
                visited[neighbor] = true;
                path.push_back(neighbor);
                dfs(path, minlen, visited);
                visited[neighbor] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string> > findLadders(string start, string end, 
      unordered_set<string> &dict) {

        dict.insert(start);
        dict.insert(end);
        
        map<string, bool> visited;
        graph = buildGraph(dict, visited);

        vector<string> path;
        path.push_back(start);

        int minlen = dict.size() + 1;
        visited[start] = true;
        des = end;

        dfs(path, minlen, visited);

        int min = dict.size() + 1;
        for(int i = 0; i < results.size(); i++){
            if(results[i].size() < min){
                min = results[i].size();
            }
        }

        vector<vector<string> > newResults;
        for(int i = 0; i < results.size(); i++){
            if(results[i].size() == min){
                newResults.push_back(results[i]);
            }
        }

        return newResults;
    }
};
