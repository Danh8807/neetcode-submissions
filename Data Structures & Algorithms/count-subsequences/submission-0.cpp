class Solution {
public:
    vector<vector<int>> memo;
    int numDistinct(string s, string t) {
        int m = s.size(); 
        int n = t.size();
        memo.resize(m, vector<int>(n, -1));
        return dfs(s, t, m, n, 0, 0);
    }

    int dfs(string &s, string &t, int m, int n, int i, int j){
        if(j >= n){
            return 1;
        }
        if(i >= m){
            return 0; 
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int res = dfs(s, t, m, n, i + 1, j);
        if(s[i] == t[j]){
            res += dfs(s, t, m, n, i + 1, j + 1);
        }
        memo[i][j] = res;
        return res;
    }
};
