class Solution {
private:
  void recursion(string result, int left, int right, vector<string> &results){
    if(left == 0 && right == 0){
      results.push_back(result);
      return;
    }
    if(left > 0){
      recursion(result + '(', left - 1, right, results);
    }
    if(left < right){
      recursion(result + ')', left, right - 1, results);
    }
  }
public:
  vector<string> generateParenthesis(int n){
    vector<string> results;
    if(n <= 0){
      return results;
    }
    recursion("", n, n, results);
    return results;
  }
};