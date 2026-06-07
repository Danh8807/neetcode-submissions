class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        dfs(s, 0, 0);
        return res;
    }
    vector<string> p;
    void dfs(string s, int i, int j){
        if( i >= s.size()){
            if(i == j){
                res.push_back(p);
            }
            return;
        }
        
        if(palindrome(s, j, i)){
            p.push_back(s.substr(j, i-j + 1));
            dfs(s, i + 1, i + 1);
            p.pop_back();
        }
        dfs(s, i + 1, j);
    }
    bool palindrome(string s, int j, int i){
        if(s.size() == 0){
            return true;
        }
        while( j < i){
            if(s[i] != s[j]){
                return false;
            }
            j++;
            i--;
        }
        return true;
    }
};
