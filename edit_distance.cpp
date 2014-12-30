class Solution {
private:
	int minValue(int a, int b, int c){
		if(a <= b){
			if(a <= c){
				return a;
			}
			else{
				return c;
			}
		}
		else{
			if(b <= c){
				return b;
			}
			else{
				return c;
			}
		}
	}
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1 == 0){
        	return len2;
        }
        if(len2 == 0){
        	return len1;
        }

        int matrix[1000][1000];
        for(int i = 0; i <= len2; i++){
        	matrix[i][0] = i;
        }
        for(int i = 0; i <= len1; i++){
        	matrix[0][i] = i;
        }
        int replacement = 0;
        int insertion = 0;
        int deletion = 0;
        for(int i = 1; i <= len1; i++){
        	for(int j = 1; j <= len2; j++){
        		if(word1[i - 1] == word2[j - 1]){
        			matrix[j][i] = matrix[j - 1][i - 1];
        		}
        		else{
        			replacement = matrix[j - 1][i - 1] + 1;
        			insertion = matrix[j - 1][i] + 1;
        			deletion = matrix[j][i - 1] + 1;
        			matrix[j][i] = minValue(replacement, insertion, deletion);
        		}
        	}
        }
        return matrix[len2][len1];
    }
};