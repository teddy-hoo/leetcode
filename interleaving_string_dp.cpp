class Solution {
    vector<vector<bool> > genEmptyVector(int row, int col){
        vector<vector<bool> > result;
        for(int i = 0; i <= row; i ++){
            vector<bool> r(col + 1, false);
            result.push_back(r);
        }
        return result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();

        if(len1 + len2 != len3){
            return false;
        }

        vector<vector<bool> > flags = genEmptyVector(len1, len2);

        flags[0][0] = true;
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                int index = i + j - 1;
                if(index < 0){
                    continue;
                }
                if(i > 0 && s1[i - 1] == s3[index] && flags[i - 1][j]){
                    flags[i][j] = true;
                }
                else if(j > 0 && s2[j - 1] == s3[index] && flags[i][j - 1]){
                    flags[i][j] = true;
                }
            }
        }

        return flags[len1][len2];
    }
};
