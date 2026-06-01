class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i < tokens.size(); i++){
            string c = tokens[i];
            if( c == "+" || c == "-" || c == "*" || c == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if( c == "+"){
                    st.push(a+b);
                }
                else if( c == "-"){
                    st.push(a-b);
                }
                else if( c == "*"){
                    st.push(a*b);
                }
                else if( c== "/"){
                    st.push(a/b);
                }
            }
            else{
                st.push(stoi(c));
            }
        }   
        res = st.top();
        return res; 
    }
};
