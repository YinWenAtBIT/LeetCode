/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        save.push_front(Interval(INT_MIN, INT_MIN));
    }
    
    void addNum(int val) {
        auto it = save.begin();
        while(it!=save.end() && it->end<=val)
            it++;
            
        auto bef = it;
        bef--;
        if(it == save.end())
        {
            if(bef->end +1== val)
                bef->end +=1;
            else
                save.push_back(Interval(val, val));
        }
        else
        {
            if(it->start <= val)
                return;
            
            if(bef->end +1 == val || it->start == val+1)
            {
                if(bef->end +1 == val)
                    bef->end +=1;
                if(it->start == val+1)
                    it->start -=1;
                if(bef ->end == it->start)
                {
                    bef->end = it->end;
                    save.erase(it);
                }
                    
            }
            else
                save.insert(it, Interval(val, val));
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res(++save.begin(), save.end());
        return res;
    }
private:
    list<Interval> save;
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */