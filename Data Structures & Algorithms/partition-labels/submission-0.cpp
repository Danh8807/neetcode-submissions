class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, -1);
        vector<int> res;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            lastIndex[c - 'a'] = i;
        }
        int index = 0;
        int size = 0;
        int last = 0;
        while(index < s.size()){
            size++;
            char c = s[index];
            last = max(last, lastIndex[c - 'a']);
            if(index == last){
                res.push_back(size);
                size = 0;
                last = 0;
            }
            index++;
        }
        return res;
    }
};
