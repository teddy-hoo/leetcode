class Solution {
private:
    unordered_map<string, vector<int> > genCache(vector<string> strs){
        unordered_map<string, vector<int> > cache;
        unordered_map<string, vector<int> >::iterator iter;
        vector<int> indexes;
        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            iter = cache.find(str);
            if(iter == cache.end()){
                indexes.clear();
                indexes.push_back(i);
                cache[str] = indexes;
            }
            else{
                iter->second.push_back(i);
            }
        }
        return cache;
    }
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<string, vector<int> > cache = genCache(strs);
        unordered_map<string, vector<int> >::iterator iter = cache.begin();
        while(iter != cache.end()){
            vector<int> indexes = iter->second;
            if(indexes.size() > 1){
                for(int i = 0; i < indexes.size(); i++){
                    result.push_back(strs[indexes[i]]);
                }
            }
            iter++;
        }
        return result;
    }
};