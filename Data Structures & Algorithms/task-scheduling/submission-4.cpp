class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>> heap;
        unordered_map<char, int> freq;
        int time = 0;
        for( char task : tasks){
            freq[task]++;
        }
        for( auto &pair: freq){
            heap.push(pair.second);
        }
        queue<pair<int,int>> q; 
        while( !heap.empty() || !q.empty()){
            time++;
            if( !heap.empty()){
                int tmp = heap.top()-1;
                heap.pop();
                if(tmp != 0){
                    q.push({tmp, time + n});
                }
            }
            if( !q.empty() && q.front().second == time){
                heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
