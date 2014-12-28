class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        if(len <= 0){
        	return 0;
        }
        vector<int> stackOfHeight;
        height.push_back(0);
        int maxArea = 0;
        for(int i = 0; i < len + 1; i++){
        	if(stackOfHeight.size() <= 0 || height[i] >= height[stackOfHeight.back()]){
        		stackOfHeight.push_back(i);
        		continue;
        	}
        	int curIndex = stackOfHeight.back();
        	stackOfHeight.pop_back();
        	int newArea = height[curIndex] * (stackOfHeight.size() <= 0 ? i : i - stackOfHeight.back() - 1);
        	maxArea = maxArea > newArea ? maxArea : newArea;
        	i--;
        }
        return maxArea;
    }
};
