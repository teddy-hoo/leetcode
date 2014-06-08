class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> resultTmp;
        vector<int> result;
        for(int i = 0; i < rowIndex; i ++){
            resultTmp.clear();
            for(int j = 0; j <= i; j ++){
                if(i - 1 < 0)
                    resultTmp.push_back(1);
                else if(j - 1 < 0)
                    resultTmp.push_back(result[0]);
                else if(j > result.size() - 1)
                    resultTmp.push_back(result[j - 1]);
                else
                    resultTmp.push_back(result[j - 1] + result[j]);
            }
            result = resultTmp;
        }
        return result;
    }
};