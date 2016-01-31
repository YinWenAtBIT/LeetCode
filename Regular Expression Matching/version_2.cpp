class Solution {
public:
    bool isMatch(string s, string p) {
            //entire match
        int s_len = s.size();
        int p_len = p.size();
        
        if(s_len==0 && p_len==0)  
            return true;  
        if(p_len==0)  
            return false;  
        vector<vector<bool> > res(s_len+1);
        for(int i=0 ;i< s_len+1; i++)
            res[i].resize(p_len+1);
        
        res[0][0] = true;  
        for(int j=0;j<p_len;j++)  
        {  
            if(p[j]=='*')  
            {  
                if(j>0 && res[0][j-1]) res[0][j+1]=true;  
                if(j<1) continue;  
                if(p[j-1]!='.')  
                {  
                    for(int i=0;i<s_len;i++)  
                    {  
                        if(res[i+1][j] || j>0&&res[i+1][j-1]   
                        || i>0 && j>0 && res[i][j+1]&&s[i]==s[i-1]&&s[i-1]==p[j-1])  
                            res[i+1][j+1] = true;  
                    }  
                }  
                else  
                {  
                    int i=0;  
                    while(j>0 && i<s_len&& !res[i+1][j-1] && !res[i+1][j])  
                        i++;  
                    for(;i<s_len;i++)  
                    {  
                        res[i+1][j+1] = true;  
                    }  
                }  
            }  
            else  
            {  
                for(int i=0;i<s_len;i++)  
                {  
                    if(s[i]==p[j]|| p[j]=='.')  
                        res[i+1][j+1] = res[i][j];  
                }  
            }  
        }  
        return res[s_len][p_len];  
    }
};