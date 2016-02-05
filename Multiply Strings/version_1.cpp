class Solution {
public:
    string multiply(string num1, string num2) {
        string res;

        
        int len1 = num1.size();
        int len2 = num2.size();
        
        int total_len = len1+len2;
        if(len1>len2)
        {
            swap(num1, num2);
            swap(len1, len2);
        }
        
        vector<vector<int>> save(len1);
        for(int i= len1-1; i>=0; i--)
        {
            int shift1 = len1 -1 -i;
            vector<int> &right_now = save[shift1];
            right_now.assign(shift1+1+len2,0);
            
            int time1 = num1[i] - '0';
            int carry = 0;
            for(int j=len2-1; j>=0; j--)
            {
                int shift2 = len2 -j -1;
                int time2 = num2[j] - '0';
                
                int out = carry+time1*time2;
                right_now[shift2+shift1] = out%10;
                carry = out/10;
            }
            if(carry>0)
                right_now[shift1+len2] = carry;
            
        }
        
        int carry=0;
        int sum=0;
        for(int i=0; i<total_len; i++)
        {
            sum =0;
            for(int j =0; j<len1; j++)
            {
                if(i<save[j].size())
                    sum+=save[j][i];
            }
            sum+= carry;
            char temp = '0'+sum%10;
            res = temp+res;
            carry = sum/10;
        }
        int pos=0;
        for(; pos<res.size(); pos++)
            if(res[pos] !='0')
                break;
        string ret(res.begin()+pos, res.end());
        if(ret.size() == 0)
            ret+= '0';
        return ret;
    }
};