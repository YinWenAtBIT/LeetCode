class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<char> p;
        
        int len = path.size();
        if(!len)
            return res;
            
        int pos = 0;
        while(pos<len)
        {
            while(pos+1< len && path[pos+1] == '/')
                pos++;
            if(pos+1< len && path[pos+1] == '.')
            {
                if(pos+2<len && path[pos+2] == '.')
                {
                    if(pos+3 >=len || path[pos+3] == '/')
                    {
                        while(!p.empty() && p.top() != '/' )
                            p.pop();
                        if(!p.empty())
                            p.pop();
                        pos+=3;
                    }
                    else
                    {
                        p.push(path[pos]);
                        pos++;
                        while(pos<len && path[pos] != '/')
                        {
                            p.push(path[pos]);
                            pos++;
                        }
                    }
                }
                else if(pos +2 >= len || path[pos+2] == '/')
                    pos+=2;
                else
                {
                    p.push(path[pos]);
                    pos++;
                    while(pos<len && path[pos] != '/')
                    {
                        p.push(path[pos]);
                        pos++;
                    }
                }
            }
            else
            {
                p.push(path[pos]);
                pos++;
                while(pos<len && path[pos] !='/')
                {
                    p.push(path[pos]);
                    pos++;
                }
            }
        }
        while(!p.empty() && p.top() == '/')
            p.pop();
        if(p.empty())
            p.push('/');
        
        while(!p.empty())
        {
            res = p.top()+res;
            p.pop();
        }
        return res;
    }
};