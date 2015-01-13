class Solution {
private:
    void generate(vector<int> num, vector<int> &result, vector<vector<int> > &results, vector<bool> &used){
        int len = num.size();
        if(result.size() == len){
            results.push_back(result);
            return;
        }
        set<int> s;
        set<int>::iterator iter;
        for(int i = 0; i < len; i++){
            if(used[i]){
                continue;
            }
            iter = s.find(num[i]);
            if(iter != s.end()){
                continue;
            }
            s.insert(num[i]);
            used[i] = true;
            result.push_back(num[i]);
            generate(num, result, results, used);
            used[i] = false;
            result.pop_back();
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int len = num.size();
        vector<vector<int> > results;
        
        if(len <= 0){
            return results;
        }
        
        vector<bool> used(len, false);
        vector<int> result;
        generate(num, result, results, used);
        
        return results;
    }
}