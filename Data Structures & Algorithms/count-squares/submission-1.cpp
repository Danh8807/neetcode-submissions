class CountSquares {
public:
    unordered_map<long long, int> m;
    CountSquares() {
        
    }
    long long encode(int x, int y) {
        return (long long)x * 1001 + y;  // tọa độ <= 1000 nên * 1001 là đủ
    }
    void add(vector<int> point) {
        m[encode(point[0],point[1])]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int ax = point[0];
        int ay = point[1];
        for(auto& [p, val]: m){
            int px = p/ 1001;
            int py = p% 1001;
            if(ax == px && ay == py){
                continue;
            }
            if(abs(px - ax) == abs(py - ay)){
                if(m.find(encode(px,ay)) != m.end() && m.find(encode(ax,py)) != m.end()){
                    res += val * m[encode(px,ay)] * m[encode(ax,py)];
                }
            }
        }
        return res;
    }
};
