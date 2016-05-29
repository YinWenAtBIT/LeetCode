class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        maxH.push(num);
        int t = maxH.top();
        maxH.pop(); minH.push(t);
        int m = maxH.size(), n = minH.size();
        if (n > m) {
            int t = minH.top();
            minH.pop(); maxH.push(t);
        }
    }

    // Returns the median of current data stream
    double findMedian() { 
        int m = maxH.size(), n = minH.size();
        if (!m && !n) return 0.0;
        if (m == n) return (maxH.top() + minH.top()) / 2.0;
        return (m > n) ? maxH.top() : minH.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> maxH;       // stores the smaller half
    priority_queue<int, vector<int>, greater<int>> minH;    // stores the larger half
};


// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();