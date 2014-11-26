class Solution {
public:
  int findMin(vector<int> &num) {
    int length = num.size();

    if(length <= 0){
      return -1;
    }

    int begin = 0;
    int end   = length - 1;

    while(begin < end){

      if(num[begin] < num[end]){
        return num[begin];
      }
      int middle = (begin + end) / 2;

      if(num[begin] < num[middle]){
        begin = middle;
      }
      else if(num[begin] > num[middle]){
        end = middle;
      }
      else{
        begin ++;
      }

    }

    return num[begin];
  }
};
