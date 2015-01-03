// box has width, depth, height
// vector<int> box, 0: width, 1: depth, 2: height

class Solution {
private:
  	void recursion(vector<vector<int> > boxes, vector<int> &indices, int &max){
  		vector<int> preBox;
  		int l = indices.size();
  		if(l > 0){
  			preBox = boxes[indices[l - 1]];
  		}
  		int validBox = 0;
  		for(int i = 0; i < boxes.size(); i++){
  			vector<int> curBox = boxes[i];
  			if(preBox.size() == 0 || (preBox[0] > curBox[0] && preBox[1] > curBox[1])){
  				validBox++;
  				indices.push_back(i);
  				recursion(boxes, indices, max);
  				indices.pop_back();
  			}
  		}
  		if(validBox == 0){
  			int sum = 0;
  			for(int i = 0; i < indices.size(); i++){
  				sum += boxes[indices[i]][2];
  			}
  			max = max > sum ? max : sum;
  		}
  	}
public:
  	int maxStackHeigth(vector<vector<int> > boxes){
    	int max = 0;
    	int len = boxes.size();
    	if(len <= 0){
      		return max;
    	}
    	vector<int> indices;
    	recursion(boxes, indices, max);
    	return max;
  	}
};
