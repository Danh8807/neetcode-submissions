class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st; 
        int res = 0;
        for( int i = 0; i < heights.size(); i++){
            int index = i;
            while( !st.empty() && st.top().first >= heights[i]){
                int area = st.top().first*(i-st.top().second);
                res = max(res,area);
                index = st.top().second;
                st.pop();
            }
            st.push({heights[i], index});
        }
        while(!st.empty()){
            int area2 = st.top().first* (heights.size()-st.top().second);
            res = max(res,area2);
            st.pop();
        }
        return res;
    }
};
