/**
 * Two pointer solution
 * Time:   O(n)
 * Space:  O(1)
 * Author: Teddy
 * Date:   04-02-2015
 */

/**
 * TWO CASES COMPARE TO DISCARD WHICH EDGE
 * * * * * * * * * * * * * * *
 * Array: 3 1 2 3 4 5 6 3 4 2
 * Size: 10
 * area[0 - 9] = 20;
 * area[0 - 8] = 27;
 * area[1 - 9] = 9;
 * * * * * * * * * * * * * * *
 * Array: 3 4 1 2 3 4 5 6 1 2
 * Size: 10
 * area[0 - 9] = 20;
 * area[0 - 8] = 9;
 * area[1 - 9] = 18;
 */

/**
 * The above two cases prove that, we should discard the little edge of current
 * pool, because we want to keep the lower edge of the pool be larger when the
 * length of the get smaller.
 */


class Solution {
private:
    int area(int i, int j, int valuei, int valuej){
        int min = valuei >= valuej ? valuej : valuei;
        return (j - i) * min;
    }
public:
    int maxArea(vector<int> &height) {

        int front = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        int curArea;
      
        while(front < end){
            curArea = area(front, end, height[front], height[end]);
            maxArea = maxArea >= curArea ? maxArea, curArea;
            if(height[front] >= height[end]){
                ++end;
            }
            else{
                ++front;
            }
        }

        return maxArea;
    }
};
