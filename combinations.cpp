void helper(vector<vector<int> >& result,vector<int> current, int k, int n, int cur )
{
  if(current.size()==k)
    {
      result.push_back(current);
      return;
    }
  for(int i=cur;i<=n;i++)
    {
      current.push_back(i);
      helper(result,current,k,n,i+1);
      current.pop_back();
    }
}
vector<vector<int> > combine(int n, int k) {
  vector<vector<int> > result;
  vector<int> solution;
  helper(result,solution, k,n,1);
  return result;
}
