class Solution {
private:
    vector<int> numbers;
    int t;
    void searchCombination(int begin, vector<vector<int> > &results, vector<int> &middleResult, int sum){
        int len = numbers.size();
        if(sum == t){
            results.push_back(middleResult);
            return;
        }
        for(int i = begin; i < len; i++){
            if(i > begin && numbers[i] == numbers[i - 1]){
                continue;
            }
            int s = sum + numbers[i];
            if(s > t){
                continue;
            }
            middleResult.push_back(numbers[i]);
            searchCombination(i + 1, results, middleResult, s);
            middleResult.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int len = num.size();
        vector<vector<int> > results;
        
        if(len <= 0){
            return results;
        }
        
        numbers = num;
        t = target;
        
        sort(numbers.begin(), numbers.end());
        
        vector<int> middleResult;
        int sum= 0;
        searchCombination(0, results, middleResult, sum);
        
        return results;
    }
};