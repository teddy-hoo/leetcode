class Solution {
private:
    vector<vector<int> > calSum(vector<int> num, int target){
        vector<vector<int> > subsets;
        vector<int> subset;
        int len = num.size();
        int left;
        
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                int start = j + 1;
                int end = len - 1;
                left = target - num[i] - num[j];
                while(start < end){
                    if(num[start] + num[end] == left){
                        subset.clear();
                        subset.push_back(num[i]);
                        subset.push_back(num[j]);
                        subset.push_back(num[start]);
                        subset.push_back(num[end]);
                        subsets.push_back(subset);
                        start++;
                        end--;
                        while(start < end && num[start] == num[start - 1]) start++;
                        while(start < end && num[end] == num[end + 1]) end--;
                    }
                    else if(num[start] + num[end] > left){
                        end--;
                    }
                    else{
                        start++;
                    }
                }
                while(j < len && num[j] == num[j + 1]){
                    j++;
                }
            }
            while(i < len && num[i] == num[i + 1]){
                i++;
            }
        }
        return subsets;
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        return calSum(num, target);
    }
};