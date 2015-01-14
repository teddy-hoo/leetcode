class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        int profit = 0;
        int len = prices.size();
        
        if(len < 2){
            return profit;
        }

        vector<int> left(len, 0);
        vector<int> right(len, 0);

        left[0] = 0;
        int min = prices[0];
        int max = 0;
        for(int i = 1; i < len; i++){
        	if(prices[i] < min){
        		min = prices[i];
        	}
        	else if(prices[i] - min > max){
        		max = prices[i] - min;
        	}
        	left[i] = max;
        }

        max = 0;
        int maxPrice = prices[len - 1];
        for(int i = len - 2; i >= 0; i--){
        	if(maxPrice - prices[i] > max){
        		max = maxPrice - prices[i];
        	}
        	else if(prices[i] > maxPrice){
        		maxPrice = prices[i];
        	}
        	right[i] = max;
        }

        for(int i = 0; i < len; i++){
        	if(profit < left[i] + right[i]){
        		profit = left[i] + right[i];
        	}
        }

        return profit;
    }
};
