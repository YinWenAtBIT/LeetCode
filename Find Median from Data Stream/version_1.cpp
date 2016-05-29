class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(nums.size() ==0)
        {
            nums.push_front(num);
            mid_it = nums.begin();
        }
        else
        {
            if(num>*mid_it)
            {
                auto temp = mid_it;
                while(temp!= nums.end() && num>*temp)
                    temp++;
                nums.insert(temp, num);
                int len = nums.size();
                if(!(len%2))
                    mid_it++;
            }
            else
            {
                auto temp = mid_it;
                while(temp!= nums.begin() && num<*temp)
                    temp--;
				if(temp != nums.begin())
					nums.insert(temp, num);
				else
				{
					if(num<nums.front())
						nums.insert(temp, num);
					else
						nums.insert(++temp, num);

				}
                int len = nums.size();
                if(len %2)
                    mid_it--;
            }
            
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int len = nums.size();
        if(len%2)
            return *mid_it;
        else
        {
            auto temp = mid_it;
            temp--;
            return (*temp+*mid_it)/2.0;
        }
    }
    
private:
    list<int> nums;
    list<int>::iterator mid_it;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();