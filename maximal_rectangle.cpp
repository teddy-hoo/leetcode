class Solution {
private:
	int largestRectangleArea(vector<vector<char> > &height, int index) {
	    int len = height.size();
	    if(len <= 0){
	    	return 0;
	    }
	    vector<int> stackOfHeight;
	    int maxArea = 0;
	    for(int i = 0; i < len; i++){
	    	if(stackOfHeight.size() <= 0 || height[i][index] >= height[stackOfHeight.back()][index]){
	    		stackOfHeight.push_back(i);
	    		continue;
	    	}
	    	int curIndex = stackOfHeight.back();
	    	stackOfHeight.pop_back();
	    	int newArea = (height[curIndex][index] - '0') * (stackOfHeight.size() <= 0 ? i : i - stackOfHeight.back() - 1);
	    	maxArea = maxArea > newArea ? maxArea : newArea;
	    	i--;
	    }
	    return maxArea;
	}
	void calculateRows(vector<vector<char> > &matrix){
		int row = matrix.size();
		int col = matrix[0].size();
		for(int i = 0; i < row; i++){
			for(int j = 1; j < col; j++){
				if(matrix[i][j] != '0'){
					matrix[i][j] = matrix[i][j] + matrix[i][j - 1] - '0';
				}
			}
		}
	}
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() <= 0){
        	return 0;
        }
        calculateRows(matrix);
        vector<char> extra;
        for(int i = 0; i < matrix[0].size(); i++){
        	extra.push_back('0');
        }
        matrix.push_back(extra);
        int max = 0;
        for(int i = 0; i < matrix[0].size(); i++){
        	int curMax = largestRectangleArea(matrix, i);
        	max = max > curMax ? max : curMax;
        }
        return max;
    }
};
