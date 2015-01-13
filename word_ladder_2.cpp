class Solution {
private:
    void dfs(unordered_set<string> dict, string start, string end,
        vector<string> path, map<string, bool> &dis, 
        vector<vector<string> > &results, int &minlen){
        
        if(start == end){
            results.push_back(path);
            minlen = path.size() < minlen ? path.size() : minlen;
            return;
        }

        if(path.size() + 1 > minlen){
            return;
        }
        
        for(int i = 0; i < start.size(); i++){
            string tmp = start;
            for(char j = 'a'; j <= 'z'; j++){
                tmp[i] = j;
                if(tmp == end ||
                    (dict.count(tmp) > 0 && 
                        (dis.count(tmp) == 0 || !dis[tmp]))){
                    path.push_back(tmp);
                    dis[tmp] = true;
                    dfs(dict, tmp, end, path, dis, results, minlen);
                    dis[tmp] = false;
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string> > findLadders(string start, string end, 
      unordered_set<string> &dict) {

        vector<vector<string> > results;
        vector<string> path;
        path.push_back(start);

        map<string, bool> dis;
        dis[start] = true;
        int minlen = dict.size() + 1;

        dfs(dict, start, end, path, dis, results, minlen);

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
