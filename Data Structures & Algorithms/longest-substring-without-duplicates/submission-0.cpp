class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len_max = 0;
        int len = 0;
        unordered_set<int> count; 
        int i = 0;
        int j = 0; 
        while( j < s.length()){
            if( count.count(s[j])){
                while(count.count(s[j])){
                    count.erase(s[i]);
                    i++;
                    len--;
                }
                count.insert(s[j]);
                len++;
            }
            else{
                count.insert(s[j]);
                len++;
                len_max = max(len_max,len);
            }
            j++;
        }
        return len_max;
    }
};
