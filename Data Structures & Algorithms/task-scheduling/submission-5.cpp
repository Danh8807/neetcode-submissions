class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int, vector<int>> heap;
        queue<pair<int,int>> q;
        unordered_map<char, int> m;
        for( char task: tasks){
            m[task]++;
        }
        for(auto &pair: m){
            heap.push(pair.second);
        }

        while( !heap.empty() || !q.empty()){
            time++;
            if(!heap.empty()){
                int tmp = heap.top()-1;
                heap.pop();
                if(tmp != 0){
                    q.push({tmp, time + n});
                }
            }
            if(!q.empty() && q.front().second == time){
                heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
