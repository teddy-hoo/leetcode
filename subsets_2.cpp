class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int length = S.size();
        vector<vector<int> > result(1);
        
        if(length == 0){
            return result;
        }
        
        std::sort(S.begin(), S.end());
        int end = 0;
        int count = 0;
        for(int i = 0; i < length; ++i){
            if(i - 1 >= 0 && S[i] == S[i - 1]){
                end = result.size() - count;
            }
            else{
                end = 0;
            }
            int j = result.size();
            count = 0;
            while(--j >= end){
                count++;
                result.push_back(result[j]);
                result.back().push_back(S[i]);
            }
        }
        return result;
    }
};
