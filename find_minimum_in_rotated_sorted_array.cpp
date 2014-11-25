class Solution {
public:
  int findMin(vector<int> &num) {
    int length = num.size();

    if(length <= 0){
      return -1;
    }

    int begin = 0;
    int end   = length - 1;

    while(1){

      if(num[begin] <= num[end]){
        return num[begin];
      }

      int middle = (begin + end) / 2 + 1;

      if(middle - 1 >= 0 && num[middle] < num[middle - 1]){
        return num[middle];
      }

      if(num[middle] >= num[begin]){
        begin = middle + 1;
      }
      else{
        end = middle - 1;
      }

    }

  }
};
