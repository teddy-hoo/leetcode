class Solution {
public:
    int majorityElement(vector<int> &num) {
        int len = num.size();
        int up = len / 2;
        unordered_map<int, int> cache;
        unordered_map<int, int>::iterator iter;

        for(int i = 0; i < len; i++){
            iter = cache.find(num[i]);
            if(iter == cache.end()){
                cache[num[i]] = 1;
            }
            else{
                iter->second++;
            }
            if(cache[num[i]] > up){
                return num[i];
            }
        }
    }
};