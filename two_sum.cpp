class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> nummap;

        int i = 0;
        for(; i < numbers.size(); i++){
            if(nummap.find(target - numbers[i]) != nummap.end())
                break;
            nummap[numbers[i]] = i;
        }
        
        return {nummap[target - numbers[i]] + 1, i + 1};
    }
};
