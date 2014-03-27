class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();  
        if (row < 1) return;  
        int col = matrix[0].size();  
        vector<bool> colRecorder(col);  
        vector<bool> rowRecorder(row);  
  
        for (int i = 0; i < row; i++)  
        {  
            for (int j = 0; j < col; j++)  
            {  
                if (matrix[i][j] == 0)  
                {  
                    rowRecorder[i] = true;  
                    colRecorder[j] = true;  
                }  
            }  
        }  
  
        for (int i = 0; i < row; i++)  
        {  
            for (int j = 0; j < col; j++)  
            {  
                if (rowRecorder[i] || colRecorder[j]) 
                    matrix[i][j] = 0;  
            }  
        }  
    }
};
