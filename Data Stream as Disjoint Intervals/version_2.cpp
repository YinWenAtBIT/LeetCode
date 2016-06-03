class SummaryRanges {  
public:  
    void addNum(int val) {  
        auto Cmp = [](Interval a, Interval b) { return a.start < b.start; };  
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);  
        int start = val, end = val;  
        if(it != vec.begin() && (it-1)->end+1 >= val) it--;  
        while(it != vec.end() && val+1 >= it->start && val-1 <= it->end)  
        {  
            start = min(start, it->start);  
            end = max(end, it->end);  
            it = vec.erase(it);  
        }  
        vec.insert(it,Interval(start, end));  
    }  
      
    vector<Interval> getIntervals() {  
        return vec;  
    }  
private:  
    vector<Interval> vec;  
};  