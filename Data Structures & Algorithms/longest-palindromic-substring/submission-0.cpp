class Solution {
public:
    string longestPalindrome(string s) {
        int idx = 0;
        int len = 0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n -1; i > -1; i--){
            for(int j = 0; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if( len < (j-i+1)){
                        idx = i;
                        len = j - i + 1;
                    }
                }
            }
        }
        return s.substr(idx, len);
    }
};
