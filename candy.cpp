class Solution {
private:
    void sortRatings(vector<int> &ratings, int begin, int end){
        if(begin >= end){
            return;
        }
        
        int pivot = ratings[begin];
        int pre = begin;
        int post = end;
        
        while(pre < post){
            while(pre < post && ratings[post] >= pivot){
                --post;
            }
            ratings[pre] = ratings[post];
            while(pre < post && ratings[pre] <= pivot){
                ++pre;
            }
            ratings[post] = ratings[pre];
        }
        
        ratings[pre] = pivot;
        sortRatings(ratings, begin, pre - 1);
        sortRatings(ratings, pre + 1, end);
    }
public:
    int candy(vector<int> &ratings) {
        map<int, int> store;
        
        sortRatings(ratings, 0, ratings.size() - 1);
        
        int min = 1;
        int pre = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] != ratings[i - 1]){
                ++pre;
            }
            min += pre;
        }
        
        return min;
    }
};
