class Solution {
public:
    int removeDuplicates(int A[], int n) {
        map<int, int> tmp;
        int index = 0;
        int count = n;
        for(int i = 0; i < n; i++){
            if(tmp.find(A[i]) == tmp.end())
                tmp.insert(pair<int, int>(A[i], 1));
            else
                tmp.find(A[i])->second += 1;
        }
        int rep;
        for(map<int, int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++){
            if(iter->second > 2){
                count -= iter->second - 2;
                rep = iter->second - 2;
                for(int i = n - 1; i >= 0; i--){
                    if(A[i] == iter->first){
                        for(int j = i; j < n - 1; j++)
                            A[j] = A[j + 1];
                        rep--;
                    }
                    if(rep <= 0)
                        break;
                }
            }
        }
        return count;
    }
};
