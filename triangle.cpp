class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        if(len <= 0){
        	return -1;
        }
        vector<int> sums;
        sums.push_back(triangle[0][0]);
        for(int i = 1; i < triangle.size(); i++){
        	vector<int> tmp;
        	tmp.push_back(sums[0] + triangle[i][0]);
        	for(int j = 1; j < triangle[i].size() - 1; j++){
        		int pre = sums[j - 1] + triangle[i][j];
        		int post = sums[j] + triangle[i][j];.
        		int min = pre < post ? pre : post;
        		tmp.push_back(min);
        	}
        	tmp.push_back(sums.back() + triangle[i].back());
        	sums = tmp;
        }
        int min = sums[0];
        for(int i = 1; i < sums.size(); i++){
        	min = min < sums[i] ? min : sums[i];
        }
        return min;
    }
};
