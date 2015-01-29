/**
 * Naive solution
 * Time:   O(n^2)
 * Space:  O(n)
 * Author: Teddy
 * Date:   29-01-2015
 */

/**
 * reach the ith child, give him or her one candy
 * check whether the previous child get higher rating recursively 
 * 1 2 3 4 5 6 5 4 3 2 1 1 2 3 4 5
 */

class Solution {
public:
    int candy(vector<int> &ratings) {
        
        int len = ratings.size();
        
        if(len <= 0){
            return 0;
        }
        
        int total = 0;
        vector<int> candies(len, 0);
        for(int i = 0; i < len; i++){
            if(i > 0 && ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
            else{
                candies[i] = 1;
            }
            total += candies[i];
            int cursor = i;
            while(cursor != 0 && 
                  ratings[cursor] < ratings[cursor - 1] &&
                  candies[cursor] >= candies[cursor - 1]){
                cursor--;
                int increasement = candies[cursor + 1] - candies[cursor] + 1;
                total += increasement;
                candies[cursor] += increasement;
            }
        }
        
        return total;
    }
};