class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> heap;
        for( vector<int> point : points){
            int distance = point[0]*point[0] + point[1]*point[1];
            heap.push({distance, {point[0],point[1]}}); 
            if( heap.size() > k){
                heap.pop();
            }
        }
        vector<vector<int>> res;
        while(!heap.empty()){
            res.push_back({heap.top().second.first,heap.top().second.second});
            heap.pop();
        }
        return res;
    }
};
