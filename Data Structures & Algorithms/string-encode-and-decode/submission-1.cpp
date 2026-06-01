class Solution {
public:

    string encode(vector<string>& strs) {
        string s; 
        for( string &a : strs){
            s += to_string(a.length())+"#"+a;
        }
        return s; 
    }

    vector<string> decode(string s) {
        vector<string> res; 
        int i = 0;
        while(i < s.length()){
            int j = i; 
            while( s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i,j - i));
            string b = s.substr(j+1, len);
            res.push_back(b);
            i = j + len + 1;
        }
        return res;
    }
};
