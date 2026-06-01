class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> heap;
        for( int i = 0; i < points.size();i++){
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            heap.push({distance,{points[i][0], points[i][1]}});
            if( heap.size() > k){
                heap.pop();
            }
        }
        vector<vector<int>> res;
        while( !heap.empty()){
            res.push_back({heap.top().second.first,heap.top().second.second});
            heap.pop();
        }
        return res;
    }
};
