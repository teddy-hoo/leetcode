class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int, int> numlist;
        for(int i = 0; i < n; i++){
            if (numlist.find(A[i]) != numlist.end())
                numlist[A[i]] = -1;
            else
                numlist[A[i]] = i;
        }
        for(map<int, int>::iterator iter = numlist.begin(); iter != numlist.end(); iter++)
            if(iter->second != -1)
                return iter->first;
    }
};
