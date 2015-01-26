/**
 * breadth first search algorithm
 * time:   depends on the pruning
 * space:  depends on the pruning, using a map to reduce the space for storing the path
 * date:   26-01-2015
 * author: Teddy
 */

/**
 * start = "hit"
 * end   = "cog"
 * dict  = ["hot", "dot", "dog", "lot", "log"]
 * res   = ["hit", "hot", "dot", "dog", "cog"], ["hit", "hot", "lot", "log", "cog"]
 */
 
/**
 * use DFS
 * state of BFS:  put the strings on the path in a queue, using "$" as a seperator
 * start of BFS:  start string and "$" seperator
 * end of BFS:    queue empty or reach the end string.
 * an extra step: return the results.
 */
 
class Solution {
private:
    bool notUsed(vector<int> v, int index){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == index){
                return false;
            }
        }
        return true;
    }
    void buildMap(unordered_set<string> dict, unordered_map<string, int> &pos,
                  vector<string> &words){
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++){
            words.push_back(*it);
            pos[*it] = words.size() - 1;
        }
    }
    vector<string> genStr(vector<int> index, vector<string> s, string end){
        vector<string> r;
        for(int i = 0; i < index.size(); i++){
            r.push_back(s[index[i]]);
        }
        r.push_back(end);
        return r;
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        
        vector<vector<string> > results;
        queue<vector<int> > q;
        unordered_map<string, int> pos;
        vector<string> words;
        words.push_back(start);
        buildMap(dict, pos, words);
        vector<int> r;
        bool reached = false;

        r.push_back(0);
        q.push(r);
        vector<int> seperator;
        seperator.push_back(-1);
        q.push(seperator);

        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            if(cur[0] == -1){
                if(reached || q.empty()){
                    break;
                }
                q.push(seperator);
                continue;
            }
            string s = words[cur.back()];
            for(int i = 0; i < s.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    string tmp = s;
                    tmp[i] = c;
                    if(tmp == end){
                        results.push_back(genStr(cur, words, end));
                        reached = true;
                    }
                    else if(dict.count(tmp) > 0 && notUsed(cur, pos[tmp])){
                        cur.push_back(pos[tmp]);
                        q.push(cur);
                        cur.pop_back();
                    }
                }
            }
        } 

        return results;
    }
};
