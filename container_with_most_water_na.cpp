/**
 * Naive solution
 * Time:   O(n^2)
 * Space:  O(1)
 * Author: Teddy
 * Date:   04-02-2015
 */

class Solution {
private:
    int area(int i, int j, int valuei, int valuej){
        int min = valuei >= valuej ? valuej : valuei;
        return (j - i) * min;
    }
public:
    int maxArea(vector<int> &height) {
  		
  		int max = 0;
  		int len = height.size();

  		for(int i = 0; i < len; i++){
  			for(int j = i + 1; j < len; j++){
  				int a = area(i, j, height[i], height[j]);
  				max = max < a ? a : max;
  			}
  		}

  		return max;
    }
};