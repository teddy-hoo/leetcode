class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if(row <= 0){
            return false;
        }

        int col = matrix[0].size();
        if(col <= 0){
            return false;
        }

        int beginr = 0;
        int endr = row - 1;
        int targetr = -1;
        while(beginr <= endr){
            int middle = (beginr + endr) >> 1;
            if(target < matrix[middle][0]){
                endr = middle - 1;
            }
            else if(target > matrix[middle][col - 1]){
                beginr = middle + 1;
            }
            else{
                targetr = middle;
                break;
            }
        }

        if(targetr < 0){
            return false;
        }

        int beginc = 0;
        int endc = col - 1;
        while(beginc <= endc){
            int middle = (beginc + endc) >> 1;
            if(target == matrix[targetr][middle]){
                return true;
            }
            else if(target > matrix[targetr][middle]){
                beginc = middle + 1;
            }
            else{
                endc = middle - 1;
            }
        }

        return false;

    }
};
