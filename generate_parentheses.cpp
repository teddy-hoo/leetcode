/**
 * backtracking algorithm
 * time:   O(2^n)
 * space:  O(2^n)
 * date:   25-01-2015
 * author: Teddy
 */

class Solution {
private:
  void recursion(string result, int left, int right, vector<string> &results){
    if(right == 0){
      results.push_back(result);
      return;
    }
    
    if(left > 0){
      recursion(result + '(', left - 1, right, results);
    }
    
    // guarantee the sequence is right when left < right
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
