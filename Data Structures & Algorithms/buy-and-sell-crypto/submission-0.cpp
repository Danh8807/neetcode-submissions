class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int max_profit = 0;
        for( int i = 0; i < prices.size(); i++){
            minimum = min(prices[i], minimum);
            int profit = prices[i] - minimum;
            max_profit = max(max_profit, profit);
        } 
        return max_profit;
    }
};
