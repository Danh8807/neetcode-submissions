class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        for(int stone: stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if( x == y){
                continue;
            }
            else{
                maxHeap.push(abs(x-y));
            }
        }
        if(maxHeap.empty()){
            return 0;
        }
        return maxHeap.top();
    }
};
