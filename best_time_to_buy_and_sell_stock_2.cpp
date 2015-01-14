class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int profit = 0;
        int len = prices.size();
        
        if(len < 2){
            return profit;
        }
        
        int min = prices[0];
        int i;
        for(i = 1; i < len; i++){
            if(prices[i] < prices[i - 1]){
                profit += prices[i - 1] - min;
                min = prices[i];
            }
        }
        
        profit += prices[i - 1] - min;
        
        return profit;
    }
};

