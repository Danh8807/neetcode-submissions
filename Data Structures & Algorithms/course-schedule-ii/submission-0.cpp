class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visiting;
    unordered_set<int> visited;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            preMap[i] = {};
        }
        for(auto& preq: prerequisites){
            preMap[preq[0]].push_back(preq[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)){
                return {};
            }
        }
        return res;
    }
    bool dfs(int crs){
        if(visiting.count(crs)){
            return false;
        }
        if(preMap[crs].empty() && !visited.count(crs)){
            res.push_back(crs);
            visited.insert(crs);
            return true;
        }
        visiting.insert(crs);
        for(int c: preMap[crs]){
            if(!dfs(c)){
                return false;
            }
        }
        visiting.erase(crs);
        preMap[crs].clear();
        if(preMap[crs].empty() && !visited.count(crs)){
            res.push_back(crs);
            visited.insert(crs);
            return true;
        }
        return true;
    }
};
