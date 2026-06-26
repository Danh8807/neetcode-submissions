class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &x, auto& y){
            return x[0] < y[0];
        });
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0;
        while(i < n){
            if(i+1 < n && intervals[i][1] >= intervals[i+1][0]){
                vector<int> newInterval(2, 0);
                newInterval[0] = intervals[i][0];
                newInterval[1] = intervals[i][1];
                while( i+1 < n && newInterval[1] >= intervals[i+1][0]){
                    newInterval[1] = max(newInterval[1], intervals[i+1][1]);
                    i++;
                }
                res.push_back(newInterval);
            }
            else{
                res.push_back(intervals[i]);
                
            }
            i++;
        }
        return res;
    }
};
