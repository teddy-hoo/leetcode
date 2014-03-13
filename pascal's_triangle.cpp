class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> row;
        vector<vector<int> > result;
        for(int i = 0; i < numRows; i ++){
            row.clear();
            for(int j = 0; j <= i; j ++){
                if(i - 1 < 0)
                    row.push_back(1);
                else if(j - 1 < 0)
                    row.push_back(result[i - 1][0]);
                else if(j > result[i - 1].size() - 1)
                    row.push_back(result[i - 1][j - 1]);
                else
                    row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result.push_back(row);
        }
        return result;
    }
};
