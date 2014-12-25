class Solution {
private:
    vector<vector<int> > calSum(vector<int> num){
        vector<vector<int> > subsets;
        vector<int> subset;
        int len = num.size();
        
        for(int i = 0; i < len; i++){
            int start = i + 1;
            int end = len - 1;
            int left = 0 - num[i];
            while(start < end){
                if(num[start] + num[end] == left){
                    subset.clear();
                    subset.push_back(num[i]);
                    subset.push_back(num[start]);
                    subset.push_back(num[end]);
                    subsets.push_back(subset);
                    start++;
                    end--;
                    while(start < end && num[start] == num[start + 1]) start++;
                    while(start < end && num[end] == num[end - 1]) end--;
                }
                else if(num[start] + num[end] > left){
                    end--;
                }
                else{
                    start++;
                }
            }
            while(i < len && num[i] == num[i + 1]){
                i++;
            }
        }
        return subsets;
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        return calSum(num);
    }
};
