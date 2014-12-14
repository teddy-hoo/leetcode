class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int length = S.size();
        vector<vector<int> > result(1);
        
        if(length == 0){
            return result;
        }
        
        std::sort(S.begin(), S.end());
        for(int i = 0; i < length; ++i){
            int j = result.size();
            while(--j >= 0){
                result.push_back(result[j]);
                result.back().push_back(S[i]);
            }
        }
        return result;
    }
};
