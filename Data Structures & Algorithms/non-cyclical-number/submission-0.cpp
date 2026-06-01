class Solution {
public:
    unordered_set<int> set;
    bool isHappy(int n) {
        int sum = 0;
        while( n != 0){
            sum += (n%10)*(n%10);
            n = n/10;
        }
        if(sum == 1){
            return true;
        }
        else if( set.find(sum) != set.end()){
            return false;
        }
        else{
            set.insert(sum);
            return isHappy(sum);
        }
    }
};
