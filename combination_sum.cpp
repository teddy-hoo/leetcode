class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> >results;
        int len = candidates.size();
        if(len <= 0){
            return results;
        }
        int sum = 0;
        int s[1000];
        int sindex = 0;
        s[0] = 0;
        sum += candidates[0];
        while(sindex >= 0){
            if(sum < target){
                s[++sindex] = s[sindex - 1];
                sum += candidates[s[sindex]];
            }
            else{
                if(sum == target){
                    vector<int> result;
                    for(int i = 0; i <= sindex; i++){
                        result.push_back(candidates[s[i]]);
                    }
                    results.push_back(result);
                }
                sum -= candidates[s[sindex]];
                sindex--;
                while(sindex >= 0 || s[sindex] + 1 >= len){
                    sindex--;
                }
                if(sindex < 0){
                    break;
                }
                s[++sindex] = s[sindex] + 1;
                sum += candidates[s[sindex]];
            }
        }
        return results;
    }
};