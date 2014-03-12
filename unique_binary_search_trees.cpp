class Solution {
public:
    int numTrees(int n) {
        vector<int> numtree;
        int sum;
        numtree.push_back(1);
        numtree.push_back(1);
        for(int i = 2; i <= n; i++){
            sum = 0;
            for(int j = 0; j < i; j++){
                sum += numtree[j] * numtree[i - j - 1];
            }
            numtree.push_back(sum);
        }
        return numtree[n];
    }
};
