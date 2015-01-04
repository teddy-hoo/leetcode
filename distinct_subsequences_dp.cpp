class Solution {
private:
    vector<vector<int> > genVector(int col, int row){
        vector<vector<int> > emptyVectors;
        for(int i = 0; i < row; i ++){
            vector<int> row;
            for(int j = 0; j < col; j++){
                row.push_back(0);
            }
            emptyVectors.push_back(row);
        }
        return emptyVectors;
    }
public:
    int numDistinct(string S, string T) {
        
        int lens = S.size();
        int lent = T.size();
        if(lens <= 0 || lent <= 0){
            return 0;
        }

        vector<vector<int> > cached = genVector(lens, lent);
        for(int it = 0; it < lent; it++){
            for(int is = it; is < lens; is++){
                int pre = is == 0 ? 0 : cached[it][is - 1];
                int cur = 0;
                if(S[is] == T[it]){
                    pre++;
                    cur = it > 0 ? cached[it - 1][is - 1] : 0;
                }
                cached[it][is] = pre + cur;
            }
        }       

        return cached[lent - 1][lens - 1];
    }
};