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
    struct Start_cmp {
    bool operator() (Interval i,Interval j) { return (i.start<j.start);}
    } start_cmp;
    
    struct End_cmp {
    bool operator() (Interval i,Interval j) { return (i.end<j.end && i.start<=j.start);}
    } end_cmp;    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len <2)
            return intervals;
            
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), start_cmp);
        stable_sort(intervals.begin(), intervals.end(), end_cmp);
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i=1; i<len; i++)
        {
            if(intervals[i].start>end)
            {
                Interval temp(start, end);
                res.push_back(temp);
                start = intervals[i].start;
                end = intervals[i].end;
            }
            end = max(end, intervals[i].end);
        }
        Interval temp(start, end);
        res.push_back(temp);
        return res;
    }
};