class Solution {
public:
    map<vector<int>, vector<int> >parent;
    vector<int> find(vector<int>& a){
        if(parent[a] != a){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    bool unite(vector<int>& a, vector<int>& b){
        vector<int> pa = find(a);
        vector<int> pb = find(b);
        if( pa == pb){
            return false;
        }
        parent[pa] = pb;
        return true;
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        int path = 0;
        priority_queue<pair<int, pair<vector<int>,vector<int>>>, vector<pair<int, pair<vector<int>,vector<int>>>>, greater<>> minHeap;
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                vector<int> point1 = points[i];
                vector<int> point2 = points[j];
                int weight = abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
                minHeap.push({weight, {point1, point2}});
            }
        }
        for(int i = 0; i < n; i++){
            parent[points[i]] = points[i];   // <-- THÊM DÒNG NÀY
        }


        int edgesUsed = 0;
        while(edgesUsed < n - 1){          // sửa: dùng số cạnh thay vì visited.size()
            auto edge = minHeap.top();
            minHeap.pop();
            if(unite(edge.second.first, edge.second.second)){ // sửa: check + merge bằng DSU
                path += edge.first;
                edgesUsed++;
            }
        }
        return path;
    }
};
