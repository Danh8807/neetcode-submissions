class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> m(num1.size() + num2.size(), 0);
        if(num1 == "0" || num2 == "0"){
            return "0";
        }    
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                int d1 = (num1[i] - '0') * (num2[j] - '0');
                m[i+j] += d1;
                m[i+j+1] += m[i+j]/10;
                m[i+j] = m[i+j]%10;
            }
        }
        int i = num1.size() + num2.size() - 1;
        while(i >= 0 && m[i] == 0){
            i--;
        }
        string res;
        while(i >= 0){
            res += (char)(m[i] + '0');
            i--;
        }
        return res;
    }
};
