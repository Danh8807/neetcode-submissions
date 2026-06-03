class MedianFinder {
public:
    priority_queue<int> left_half;
    priority_queue<int, vector<int>, greater<int>> right_half;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int left = left_half.size();
        int right = right_half.size();
        if( left == 0){
            left_half.push(num);
            
        } 
        else if( left == right){
            if( num > left_half.top() && num < right_half.top()){
                left_half.push(num);
            }
            else if(num <= left_half.top()){
                left_half.push(num);
            }
            else if(num >= right_half.top()){
                int tmp = right_half.top();
                right_half.pop();
                left_half.push(tmp);
                right_half.push(num);
            }
        }
        else if( left > right){
            if(num <= left_half.top()) {
                int tmp = left_half.top();
                left_half.pop();
                right_half.push(tmp);
                left_half.push(num);
            }
            else{
                right_half.push(num);
            }

        }
    }
    
    double findMedian() {
        if(left_half.size() > right_half.size()){
            return left_half.top();
        }
        else {
            return ((double)left_half.top() + right_half.top())/2;
        }
    }
};
