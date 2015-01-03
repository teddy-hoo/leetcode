class Solution {
private:
    vector<int> insertValue(vector<int> permutation, int pos){
        bool inserted = false;
        vector<int> permutation;
        for(int k = 0; k <= results[j].size(); k++){
            if(k == pos){
                permutation.push_back(num[i]);
                inserted = true;
            }
            else{
                permutation.push_back(inserted ? results[j][k - 1] : results[j][k]);
            }
        }
        return permutation;
    }
public:
    vector<vector<int> > permute(vector<int> &num) {  
        vector<vector<int> > results;
        int len = num.size();
        if(len <= 0){
            return results;
        }
        vector<int> result;
        result.push_back(num[0]);
        results.push_back(result);
        for(int i = 1; i < len; i++){
            int max = results[0].size();
            vector<vector<int> > newResults;
            for(int j = 0; j < results.size(); j++){
                for(int insert = 0; insert <= max; insert++){
                    newResults.push_back(insertValue(results[j], insert));
                }
            }
            results = newResults;
        }
        return results;
    }
};