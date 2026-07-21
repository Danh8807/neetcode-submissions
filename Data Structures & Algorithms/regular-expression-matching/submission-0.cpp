class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        dp.resize(m + 1, vector<int>(n+1, -1));
        return dfs(s, p, m, n, 0, 0);
    }
    bool dfs(string &s, string &p, int m, int n, int i, int j){
        if( j == n){
            return i == m;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool match = i < m && (s[i] == p[j] || p[j] == '.');
        if( j + 1 < n && p[j+1] == '*'){
            dp[i][j] = dfs(s, p, m, n, i, j+2) || (match && dfs(s, p , m, n, i + 1, j));
        }
        else{
            dp[i][j] = match && dfs(s, p , m, n, i + 1, j + 1);
        }
        return dp[i][j];
    }
};
