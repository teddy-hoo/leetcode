class Solution {
private:
    int add(vector<int> list){
        int sum = 0;
        for(int i = 0; i < list.size(); i++){
            sum += list[i];
        }
        return sum;
    }
    vector<vector<int> > calSum(vector<vector<int> > subsets, int target){
        vector<vector<int> > results;
        for(int i = 0; i < subsets.size(); i++){
            if(subsets[i].size() == 4 && add(subsets[i]) == target){
                results.push_back(subsets[i]);
            }
        }
        return results;
    }
    vector<vector<int> > genSubset(vector<int> num){
        vector<vector<int> > subsets;
        vector<int> subset;
        subsets.push_back(subset);
        for(int i = 0; i < num.size(); i++){
            for(int j = 0; j < subsets; j++){
                vector<int> tmp = subsets[j];
                if(tmp.size() >= 4){
                    continue;
                }
                subsets.push_back(tmp.push_back[num[i]]);
            }
        }
        return subsets;
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size() <= 0){
            return results;
        }
        vector<vector<int> > subsets = genSubset(num);
        return calSum(subsets, target);
    }
};