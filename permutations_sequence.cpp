class Solution {
private:
	int getS(vector<bool> &used, int s){
		int c = -1;
		for(int i = 0; i < used.size(); i++){
			if(!used[i]){
				c++;
			}
			if(c == s){
				used[i] = true;
				return i;
			}
		}
	}
public:
    string getPermutation(int n, int k) {
        string result;
        if(n <= 0){
        	return result;
        }
        vector<int> numbers(n);
        numbers[0] = 1;
        numbers[1] = 1;
       	for(int i = 2; i < n; i++){
       		numbers[i] = numbers[i - 1] * i;
       	}
       	vector<bool> used(n, false);
       	k--;
       	for(int i = 0; i < n; i++){
       		int num = numbers[n - i - 1];
       		int s = k / num;
       		result += getS(used, s) + '1';
       		k = k % num;
       	}

       	return result;
    }
};