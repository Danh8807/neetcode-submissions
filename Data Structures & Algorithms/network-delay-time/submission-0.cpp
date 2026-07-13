class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = 0;
        unordered_map<int, vector<pair<int,int>>> edges;
        for(vector<int> node: times){
            edges[node[0]].push_back({node[1],node[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});
        unordered_set<int> visited;
        while(!minHeap.empty()){
            auto cur = minHeap.top();
            minHeap.pop();
            int w1 = cur.first;
            int n1 = cur.second;
            if(visited.count(n1)){
                continue;
            }
            visited.insert(n1);
            t = w1; 
            if(edges.count(n1)){
                for(const auto& next : edges[n1]){
                    int n2 = next.first;
                    int w2 = next.second;
                    if(!visited.count(n2)){
                        minHeap.push({w1 + w2, n2});
                    }
                }
            }
        }
        return visited.size() == n? t : -1;
    }
};
