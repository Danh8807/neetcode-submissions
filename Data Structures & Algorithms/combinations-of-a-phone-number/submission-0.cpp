class Solution {
public:
    unordered_map<char, vector<char>> m;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        if(digits.size() == 0){
            return res;
        }
        dfs(digits, 0);
        return res;
    }
    string com;
    void dfs(string s, int i){
        if( i == s.size()){
            res.push_back(com);
            return;
        }
       
        for(int j = 0; j < m[s[i]].size(); j++){
            com += m[s[i]][j];
            dfs(s, i + 1);
            com.pop_back();
        }
        
    }
};
