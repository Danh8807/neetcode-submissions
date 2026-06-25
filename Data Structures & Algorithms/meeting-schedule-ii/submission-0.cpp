/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](auto &x, auto& y){
            return x.start < y.start;
        });
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < intervals.size(); i++){
            if(!heap.empty() && intervals[i].start >= heap.top()){
                heap.pop();
            }
            heap.push(intervals[i].end);
        }
        return heap.size();
    }
};
