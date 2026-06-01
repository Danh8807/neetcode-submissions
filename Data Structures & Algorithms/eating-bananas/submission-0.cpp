class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        while( l <= r){
            int mid = (l+r)/2;
            int time = 0;
            for(int x: piles){
                time += ceil((double)x / mid);
            }
            if( time > h){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

        }
        return l;
    }
};
