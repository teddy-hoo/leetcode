/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        int len = intervals.size();
        vector<Interval> newIntervals;
        
        if(len <= 0){
            return newIntervals;
        }
        
        bool pushed = false;
        for(int i = 0; i < len; i++){
            if(intervals[i].end < newInterval.start){
                newIntervals.push_back(intervals[i]);
                continue;
            }
            if(intervals[i].start > newInterval.end){
                if(!pushed){
                    newIntervals.push_back(newInterval);
                    pushed = true;
                }
                newIntervals.push_back(intervals[i]);
                continue;
            }
            newInterval.start = newInterval.start < intervals[i].start ? newInterval.start : intervals[i].start;
            newInterval.end = newInterval.end > intervals[i].end ? newInterval.end : intervals[i].end;
        }
        
        if(!pushed){
            newIntervals.push_back(newInterval);
        }
        
        return newIntervals;
    }
};
