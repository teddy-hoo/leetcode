class Solution {
private:
	int setValue(int **cache, int row, int col){
		int sum = 1;
		if(i - 1 >= 0 && j - 1 >= 0){
			if(cache[i - 1][j - 1] == 0){
				sum += cache[i - 1][j] > cache[i][j - 1] ? cache[i - 1][j] : cache[i][j - 1];
			}
			else if(cache[i - 1][j] == 0){
				if(cache[i][j - 1] != 0){
					sum += cache[i][j - 1] - cache[i - 1][j - 1];
				}
			}
			else if(cache[i][j - 1] == 0){
				sum += cache[i - 1][j] - cache[i - 1][j - 1];
			}
			else{
				sum += cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1];
			}
		}
		else if(i - 1 >= 0){
			sum += cache[i - 1][j];
		}
		else if(j - 1 >= 0){
			sum += cache[i][j - 1];
		}
	}
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int height = matrix.size();
        if(height <= 0){
        	return 0;
        }
        int width = matrix[0].size();
        int cache[height][width];
        int max = 0;

        for(int i = 0; i < height; i++){
        	for(int j = 0; j < width; j++){
        		if(matrix[i][j] == '0'){
        			cache[i][j] = 0;
        			continue;
        		}
        		int sum = setValue(cache, i , j);
        		max = sum > max ? sum : max;
        		cache[i][j] = sum;
        	}
        }

        return max;
    }
};