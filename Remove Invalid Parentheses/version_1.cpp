class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        vector<string> res;
        queue<pair<string, int>> que;
        que.push(pair<string, int>(s, 0));
        
        if(is_valid(s))
            res.push_back(s);
        else
            bfs(res, que);
		if(res.empty())
			res.push_back("");
        return res;
    }
    
    bool is_valid(string &str)
    {
        int len = str.size();
        stack<bool> st;
        for(int i=0; i<len; i++)
        {
            if(str[i] == '(')
                st.push(true);
            else if(str[i] == ')')
            {
                if(st.empty())
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
    
    bool bfs(vector<string> &res, queue<pair<string, int>> &que)
    {
        int len_bf = que.front().first.size();
        bool success_now = false;
        while(!que.empty())
        {
            auto it = que.front();
            que.pop();
            string temp = it.first;
            int start = it.second;
            
            int len = temp.size();
            if(len <len_bf)
            {
                if(success_now)
                    break;
                len_bf = len;
            }
            
            if(start>=len)
                continue;
            
            
            vector<string> next;
    		vector<int> locate;
            for(int i= start; i<len; i++)
            {
                if(temp[i] == '(' || temp[i] == ')')
                {
                    string now = temp;
                    now.erase(now.begin()+i);
                    if(find(next.begin(), next.end(), now) != next.end())
                        continue;
                        
                    next.push_back(now);
    				locate.push_back(i);
                    if(is_valid(now))
                    {
                        success_now = true;
                        res.push_back(now);
    					
                    }
    
                }
            }
            if(success_now)
                continue;
            else
            {
                for(int i=0; i<next.size(); i++)
                    que.push(pair<string, int>(next[i], locate[i]));
            }
        }
        return true;
    }
};