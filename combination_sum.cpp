class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > results;
        int len = candidates.size();
        if(len <= 0){
            return results;
        }
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> stk;
        stk.push_back(0);
        sum += candidates[0];
        while(stk.size() >= 0){
            if(sum < target){
                int p = stk.back();
                stk.push_back(p);
                sum += candidates[p];
            }
            else{
                if(sum == target){
                    vector<int> result;
                    for(int i = 0; i < stk.size(); i++){
                        result.push_back(candidates[stk[i]]);
                    }
                    results.push_back(result);
                }
                int pos = stk.back();
                sum -= candidates[pos];
                stk.pop_back();
                if(stk.size() > 0){
                    pos = stk.back();
                    sum -= candidates[pos];
                    stk.pop_back();
                }
                while(stk.size() > 0 && pos + 1 >= len){
                    pos = stk.back();
                    sum -= candidates[stk.back()];
                    stk.pop_back();
                }
                if(pos + 1 >= len){
                    break;
                }
                stk.push_back(pos + 1);
                sum += candidates[stk.back()];
            }
        }
        return results;
    }
};