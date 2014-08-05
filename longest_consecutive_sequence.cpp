class Solution {
public:
    set<int> flag;
    int findBound(int n , bool asc){
        int ans = 0;
        set<int>::iterator iter;
        while((iter = flag.find(n)) != flag.end()){
            flag.erase(iter);
            ans ++;
            if(asc) n-- ; else n++;
        }
        return ans;
    }
    int longestConsecutive(vector<int> &num) {
        int ans = 0;
        flag.clear();
        for(int i = 0 ; i < num.size() ; i++)
           flag.insert(num[i]);
        for(int i = 0 ; i < num.size(); i++){
            ans = max(findBound(num[i],true) + findBound(num[i]+1,false) , ans); 
        }
        return ans;
    }
};