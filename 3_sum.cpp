class Solution {
private:
    map<int, int> buildMap(vector<int> num){
        map<int, int> m;
        for(int i = 0; i < num.size(); i++){
            m[num[i]] = i;
        }
        return m;
    }
    vector<vector<int> > calSum(vector<int> num, map<int, int> m){
        vector<vector<int> > subsets;
        vector<int> subset;
        map<int, int>::iterator iter;
        
        for(int i = 0; i < num.size(); i++){
            for(int j = i + 1; j < num.size(); j++){
                iter = m.find(0 - num[i] - num[j]);
                if(iter != m.end() && iter->second > j){
                    subset.clear();
                    subset.push_back(num[i]);
                    subset.push_back(num[j]);
                    subset.push_back(iter->first);
                    subsets.push_back(subset);
                }
            }
        }
        return subsets;
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        map<int, int> m = buildMap(num);
        return calSum(num, m);
    }
};
