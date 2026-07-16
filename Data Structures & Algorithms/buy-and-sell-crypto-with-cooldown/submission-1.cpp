class Solution {
public:
    unordered_map<string, int> dp;
    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, false);
    }
     
    int dfs(vector<int>& prices, int i, bool status){
        if(i >= prices.size()){
            return 0;
        }
        string key = to_string(i) + "-" + to_string(status);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        if(status == false){
            return dp[key] = max(dfs(prices, i + 1, true) - prices[i], dfs(prices, i + 1, false));
        }
        else{
            return dp[key] = max(dfs(prices, i + 2, false) + prices[i], dfs(prices, i + 1, true));
        }
    }
};
