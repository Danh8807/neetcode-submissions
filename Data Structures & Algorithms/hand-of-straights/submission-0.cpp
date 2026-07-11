class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int,int> freq;
        for(int card: hand){
            freq[card]++;
        }
        for(int num: hand){
            if(freq[num] > 0){
                for(int i = num; i < num + groupSize; i++){
                    if(freq[i] == 0 ){
                        return false;
                    }
                    freq[i]--;
                }
            }
            
            
        }
        return true;
    }
};
