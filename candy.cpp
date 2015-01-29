/**
 * Greey algorithm
 * Time:   O(n)
 * Space:  O(n)
 * Author: Teddy
 * Date:   29-01-2015
 */

/**
 * two round traversal, asscending order and descending order
 * 1 2 3 2 1 4 5 8 1 4 9 2
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
    
        candies[0] = 1;
        total++;
        
        // assending order traversal
        for(int i = 1; i < len; i++){
            candies[i] = ratings[i] > ratings[i - 1] ? candies[i - 1] + 1 : 1;
            total += candies[i];
        }
        
        // descending order traversal
        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]){
                int increasement = candies[i + 1] - candies[i] + 1;
                candies[i] += increasement;
                total += increasement;
            }
        }
        
        return total;
    }
};