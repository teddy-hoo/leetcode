class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)
            return 0;
        int max = 0;
        int min = prices[0];
        int i = 1;
        int j = 0;
        for(;i < prices.size(); i++){
            if(prices[i] < prices[i - 1]){
                if(prices[i] < min)
                    min = prices[i];
                continue;
            }
            if(prices[i] - min > max)
                max = prices[i] - min;
        }
        return max;
    }
};