#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> nummap;
        vector<int>::iterator iter = numbers.begin();
        int i = 0;
        for(; i < numbers.size(); i++){
            if(nummap.find(target - numbers[i]) != nummap.end())
                break;
            nummap.insert(map<int, int>::value_type(numbers[i], i));
        }
        vector<int> res = {nummap[target - numbers[i]] + 1, i + 1};
        return res;
    }
};
