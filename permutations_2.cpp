class Solution {
private:
    void searchPermute(vector<int> num, vector<int> &indices, vector<vector<int> > &results, vector<bool> &used){
        int len = num.size();
        if(indices.size() == len){
            vector<int> result;
            for(int i = 0; i < len; i++){
                result.push_back(num[indices[i]]);
            }
            results.push_back(result);
        }
        else{
            for(int i = 0; i < len; i++){
                if(!used[i]){
                    used[i] = true;
                    indices.push_back(i);
                    searchPermute(num, indices, results, used);
                    used[i] = false;
                    indices.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {  
        vector<vector<int> > results;
        int len = num.size();
        if(len <= 0){
            return results;
        }
        vector<bool> used(len, false);
        vector<int> indices;
        searchPermute(num, indices, results, used);
        return results;
    }
};