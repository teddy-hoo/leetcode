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