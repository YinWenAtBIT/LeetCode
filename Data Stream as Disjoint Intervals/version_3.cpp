class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        save.insert(Interval(INT_MIN, INT_MIN));
    }

    struct cmp_struct
    {
        bool operator()(const Interval &l, const Interval &r)
        {
            return l.start<r.start;
        }
    }cmp;
    
    void addNum(int val) {
        Interval new_one(val, val);
		auto it = save.lower_bound(new_one);
		int start = val, end= val;
		auto temp = it;
		temp--;
		if(temp->end+1 >= val) it--;  
        while(it != save.end() && val+1 >= it->start && val-1 <= it->end)  
        {  
            start = min(start, it->start);  
            end = max(end, it->end);  
            it = save.erase(it);  
        }  
        save.insert(it,Interval(start, end));
    }
   
    
    vector<Interval> getIntervals() {
        vector<Interval> res(++save.begin(), save.end());
        return res;
    }
private:
    set<Interval, cmp_struct> save;
    
};