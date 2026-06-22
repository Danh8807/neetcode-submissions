class CountSquares {
public:
    map<pair<int,int>, int> m;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int ax = point[0];
        int ay = point[1];
        for(auto& [p, val]: m){
            int px = p.first;
            int py = p.second;
            if(ax == px && ay == py){
                continue;
            }
            if(abs(px - ax) == abs(py - ay)){
                if(m.find({px,ay}) != m.end() && m.find({ax,py}) != m.end()){
                    res += val * m[{px,ay}] * m[{ax,py}];
                }
            }
        }
        return res;
    }
};
