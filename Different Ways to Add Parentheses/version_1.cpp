class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.size();
        vector<int> temp;
        if(!len)
            return temp;
        return get_diff_Compute(input, 0, len-1);
    }
    vector<int> get_diff_Compute(string & input, int l, int r)
    {
        vector<int> res;
        if(r<l)
            return res;
        if(r== l)
        {
            if(is_num(input[l]))
                res.push_back(input[l]-'0');
            return res;
        }
        
        bool flag = false;
        
        for(int i=l+1; i<r; i++)
        {
            if(is_num(input[i]))
                continue;
            
            flag = true;
            vector<int> L_list = get_diff_Compute(input, l, i-1);
            vector<int> R_list = get_diff_Compute(input, i+1, r);
            for(int j=0; j<L_list.size(); j++)
            {
                for(int k=0; k<R_list.size(); k++)
                {
                    if(input[i] == '+')
                        res.push_back(L_list[j]+R_list[k]);
                    else if(input[i] == '-')
                        res.push_back(L_list[j]-R_list[k]);
                    else if(input[i] == '*')
                        res.push_back(L_list[j]*R_list[k]);
                    else if(input[i] == '/')
                        res.push_back(L_list[j]/R_list[k]);
                }
            }
        }
        if(!flag)
        {
            string sub(input.begin()+l, input.begin()+r+1);
            int temp = atoi(sub.c_str());
            res.push_back(temp);
        }
        return res;
    }
    bool is_num(char c)
    {
        return c>='0' && c<='9';
    }
    
};