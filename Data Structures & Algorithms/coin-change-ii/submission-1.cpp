class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        memo.resize(coins.size() + 1, vector<int>(amount + 1, -1));
        return dfs(0, coins, amount);
    }
    int dfs(int i, vector<int>& coins, int amount){
        if(amount == 0){
            return 1;
        }
        if(amount < 0 || i >= coins.size()){
            return 0;
        }
        if(memo[i][amount] != -1){
            return memo[i][amount];
        }
        return memo[i][amount] = dfs(i, coins, amount - coins[i]) + dfs(i+1, coins, amount);
    }
};
