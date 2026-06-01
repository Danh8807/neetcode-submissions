class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> res;
        for( int i = 0; i < strs.size(); i++){
            vector<int> count(26, 0);
            for( int j = 0; j < strs[i].size(); j++){
                int index = strs[i][j] - 'a';
                count[index]++;
            }
            string key = to_string(count[0]);
            for( int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            map[key].push_back(strs[i]);
        }
        for( auto& pair : map){
            res.push_back(pair.second);
        }
        return res;
    }
};
