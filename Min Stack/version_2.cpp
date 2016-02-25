class MinStack {
public:
    stack<int> st;
    list<int> order;
    unordered_map<int, vector<list<int>::iterator>> dic;
    int min_num;
    void push(int x) {
        st.push(x);
        insert_list(x);
    }

    void pop() {
        int temp = st.top();
        st.pop();
        erase_list(temp);
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return order.front();
    }
    void insert_list(int x)
    {
		if(order.empty())
		{
			order.push_back(x);
			dic[x].push_back(order.begin());
			return;
		}
		auto it = order.rbegin();
        for(; it!= order.rend(); it++)
            if(x > *it)
            {
				auto i(it.base());
                order.insert(i, x);
                i --;
                dic[x].push_back(i);
                break;
            }
		if(it == order.rend())
		{
			order.insert(order.begin(), x);
			dic[x].push_back(order.begin());
		}
    }
    void erase_list(int x)
    {
        list<int>::iterator & it = dic[x].back();
        order.erase(it);
        dic[x].pop_back();
    }
};