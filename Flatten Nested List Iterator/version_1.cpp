/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int len = nestedList.size();
        if(!len)
            return;
        for(int i=0; i<len; i++)
            get_num(nestedList[i]);
        index=0;
    }

    int next() {
        return save[index++];
    }

    bool hasNext() {
        return index<save.size();
    }
    void get_num(const NestedInteger & nest)
    {
        if(nest.isInteger())
            save.push_back(nest.getInteger());
        else
        {
            const vector<NestedInteger> &nestedList = nest.getList();
            int len = nestedList.size();
            for(int i=0; i<len; i++)
                get_num(nestedList[i]);
        }
    }
private:
    vector<int> save;
    int index;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */