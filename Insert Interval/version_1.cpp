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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        if(len <1)
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        int start =newInterval.start, end = newInterval.end;
        int i;
        for(i=0; i<len; i++)
        {
            if(newInterval.start> intervals[i].end)
                continue;
            start = min(intervals[i].start, newInterval.start);
            if(newInterval.end < intervals[i].start)
            {
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }
            end = max(newInterval.end, intervals[i].end);

            break;
        }
        
        vector<Interval> res;
        res.reserve(len);
        res.assign(intervals.begin(), intervals.begin()+i);
        while(i<intervals.size() && intervals[i].start<=end )
        {
            end = max(intervals[i].end, end);
            i++;
        }
        Interval temp(start, end);
        res.push_back(temp);
        res.insert(res.end(), intervals.begin()+i, intervals.end());
        return res;
    }
};