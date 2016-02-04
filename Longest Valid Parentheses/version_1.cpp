class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(!len)
            return 0;
        int left=0; 
        int right =0;
        int start = 0;
        int max = 0;
        int last_success_start =-1;
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(')
                left++;
            else
                right ++;
            if(left>right)
                continue;
            else if(left == right)
            {
                if(left+right >max)
                {
                    max = left+right;
                    last_success_start = start;
                }
            }
            else
            {
                while(left<right)
                {
                    if(s[start] == '(')
                        left --;
                    else
                        right --;
                    start ++;
                }
            }
        }
        if(right<left)
        {
            if(last_success_start == -1)
                max = 2*right;
            else
            {
                if(last_success_start < start && 2*right > max)
                    max = 2*right;
                if(last_success_start == start && 2*right >2*max)
                    max = 2*right - max;
            }
        }
        return max;
    }
};