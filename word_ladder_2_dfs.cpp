/**
 * This is the document created by Lingchuan Hu.
 * For Facebook interview
 */

/**
 * start = "hit"
 * end   = "cog"
 * dict  = ["hot", "dot", "dog", "lot", "log"]
 * res   = ["hit", "hot", "dot", "dog", "cog"], ["hit", "hot", "lot", "log", "cog"]
 */
 
/**
 * use BFS
 * state of BFS: dict, used, curPath, results, min
 * start of BFS: dict, NULL, "hit", NULL
 * end of BFS  : the length of curPath, is bigger than min or all words are used.
 * an extra step: remove the resuts whose length is bigger than min.
 */
 
class Solution {
private:
    void searchPath(unordered_set<string> dict, unordered_set<string> used,
                    string end, vector<string> result,
                    int &min, vector<vector<string> > &results){
              
        string cur = result.back();
        
        if(result.size() > min){
            return;
        }
      
        if(cur == end){
            results.push_back(result);
            min = result.size();
            return;
        }
      
        for(int i = 0; i < cur.size(); i++){
            for(char c = 'a'; c <= 'z'; c++){
                string tmp = cur;
                tmp[i] = c;
                if(dict.count(tmp) > 0 && used.count(tmp) == 0){
                    used.insert(tmp);
                    result.push_back(tmp);
                    searchPath(dict, used, end, result, min, results);
                    used.erase(tmp);
                    result.pop_back();
                }
            }
        } 
    }
    
    vector<vector<string> > genEventual(vector<vector<string> > results, int min){
        vector<vector<string> > e;
        for(int i = 0; i < results.size(); i++){
            if(results[i].size() == min){
                e.push_back(results[i]);
            }
        }
        return e;
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        
        unordered_set<string> used;
        int min = dict.size();
        vector<vector<string> > results;
        vector<string> result;
        
        result.push_back(start);
        dict.insert(end);
        used.insert(start);
        
        searchPath(dict, used, end, result, min, results);

        return genEventual(results, min);
    }
};
