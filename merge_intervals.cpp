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
private:
	void quickSort(vector<Interval> &intervals, int begin, int end){
		if(begin >= end){
			return;
		}
		int first = begin;
		int last = end;
		Interval pivot = intervals[begin];
		while(first < last){
			while(first < last && intervals[last].start >= pivot.start){
				last--;
			}
			intervals[first] = intervals[last];
			while(first < last && intervals[first].start <= pivot.start){
				first++;
			}
			intervals[last] = intervals[first];
		}
		intervals[first] = pivot;
		quickSort(intervals, begin, first - 1);
		quickSort(intervals, first + 1, end);
	}
    void sortIntervals(vector<Interval> &intervals){
        if(intervals.size() > 0){
        	quickSort(intervals, 0, intervals.size() - 1);
        }
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> results;
        int len = intervals.size();
        if(len <= 0){
        	return results;
        }
        sortIntervals(intervals);
        int i = 0;
        for(int i = 0; i < len; i++){
        	int begin = intervals[i].start;
        	int end = intervals[i].end;
        	while(i + 1 < len && intervals[i + 1].start <= end){
        		i++;
        		end = end > intervals[i].end ? end : intervals[i].end;
        	}
        	Interval newInterval(begin, end);
        	results.push_back(newInterval);
        }
        return results;
    }
};
