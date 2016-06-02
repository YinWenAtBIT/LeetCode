class Solution {  
public:  
    vector<string> findItinerary(vector<pair<string, string>> tickets) {  
        vector<string> result;  
        int n = tickets.size();  
  
        if (n < 1)  
            return result;  
    
  
        unordered_map<string, multiset<string> > buf;  
        for (int i = 0; i < n; i++)  
            buf[tickets[i].first].insert(tickets[i].second);  
        
  
        stack<string> dfs;  
        dfs.push("JFK");  
        while (!dfs.empty())  
        {  
            string top = dfs.top();  
            if (buf[top].empty())  
            {  
                result.push_back(top);  
                dfs.pop();  
            }  
            else  
            {  
                dfs.push(*buf[top].begin());  
                buf[top].erase(buf[top].begin());  
            }  
        }  
        reverse(result.begin(), result.end());  
  
        return result;  
    }  
};  