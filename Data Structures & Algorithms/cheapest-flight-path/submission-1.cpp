class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, 1001);
        prices[src] = 0;
        for(int i = 0; i < k + 1; i++){
            vector<int> copy = prices;
            for(const auto& flight: flights){
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];
                if(prices[s] == 1001){
                    continue;
                }
                if(prices[s] + p < copy[d]){
                    copy[d] = prices[s] + p;
                } 
            }
            prices = copy;
        }
        return prices[dst] == 1001 ? -1: prices[dst];
    }
};
