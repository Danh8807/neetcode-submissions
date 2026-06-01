class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> track;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        track[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = track[key].size()-1;
        string result = "";
        if( track[key].size() == 0){
            return "";
        }
        while( l <= r){
            int mid = l + (r-l)/2;
            if( track[key][mid].first <= timestamp){
                result = track[key][mid].second;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        return result;
    }
};
