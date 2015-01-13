class Solution {
private:
    vector<int> numbers;
    int t;
    bool duplicate(vector<vector<int> > result, vector<int> mr){
        int i, j, k;
        for(i = 0; i < result.size(); i++){
            for(j = 0, k = 0; j < result[i].size(); j++, k++){
                if(k == mr.size() || result[i][j] != mr[k]){
                    break;
                }
            }
            if(k == mr.size() && j == result[i].size()){
                return true;
            }
        }
        return false;
    }
    void searchCombination(int begin, vector<vector<int> > &results, vector<int> &middleResult, int sum){
        int len = numbers.size();
        if(begin == len){
            if(sum == t){
                if(!duplicate(results, middleResult)){
                    results.push_back(middleResult);
                }
                return;
            }
            return;
        }
        if(sum == t){
            if(!duplicate(results, middleResult)){
                results.push_back(middleResult);
            }
            return;
        }
        for(int i = begin; i < len; i++){
            int s = sum + numbers[i];
            if(s <= t){
                middleResult.push_back(numbers[i]);
                searchCombination(i + 1, results, middleResult, s);
                middleResult.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int len = num.size();
        vector<vector<int> > results;
        
        if(len <= 0){
            return results;
        }
        
        numbers = num;
        t = target;
        
        sort(numbers.begin(), numbers.end());
        
        vector<int> middleResult;
        int sum= 0;
        searchCombination(0, results, middleResult, sum);
        
        return results;
    }
};