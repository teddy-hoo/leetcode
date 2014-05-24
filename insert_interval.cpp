/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
#define EDGE -99999
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> newlist;
        bool pushed = false;
        Interval merged(newInterval.start, newInterval.end);
        for(int i = 0; i < intervals.size(); ++i){
            if(intervals[i].end < newInterval.start){
                newlist.push_back(intervals[i]);
                continue;
            }
            if(intervals[i].start > newInterval.end){
                if(merged.start == EDGE){
                    merged.start = newInterval.start;
                }
                if(merged.end == EDGE){
                    merged.end = newInterval.end;
                }
                if(!pushed){
                    newlist.push_back(merged);
                    pushed = true;
                }
                newlist.push_back(intervals[i]);
                continue;
            }
            
            merged.start = intervals[i].start < merged.start ? intervals[i].start : merged.start;
            merged.end = intervals[i].end > merged.end ? intervals[i].end : merged.end;
        }
        if(!pushed){
            newlist.push_back(merged);
        }
        return newlist;
    }
};
