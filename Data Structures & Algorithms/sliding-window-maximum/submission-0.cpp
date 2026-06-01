class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq; 
        for( int i = 0; i < k; i++){
            pq.push({nums[i],i});
        }
        vector<int> res;
        int l = 0;
        res.push_back(pq.top().first);
        for( int r = k; r < nums.size(); r++){
            pq.push({nums[r],r});

            l++;
            while(pq.top().second < l){
                pq.pop();
            }

            res.push_back(pq.top().first);
        }
        return res;
    }
};
