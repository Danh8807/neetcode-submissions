class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return res;
    }
    string subset;
    void dfs(int n, int open, int close){
        if(close > open || open > n){
            return;
        }
        if(subset.size() == 2*n && close == open){
            res.push_back(subset);
            return;
        }
        subset.push_back('(');
        dfs(n, open + 1, close);
        subset.pop_back();
        subset.push_back(')');
        dfs(n, open, close+1);
        subset.pop_back();
    }
};
