class Solution {
public:
int longestValidParentheses(string s) {
        int len = s.length();
        if(len<2)
          return 0;
        int max = 0;
        int *dp = new int[len];
        for(int k = 0;k<len;k++)//把辅助数组清空，存储为0
         dp[k] = 0;
        for(int i = len-2;i>=0;i--)
        {
          if(s[i] == '(')//只对左括号处理，右括号在数组中存储为0
          {
            int j = i+1+dp[i+1];//计算与当前左括号匹配的右括号的位置。可能存在也可能不存在
            if(j<len && s[j] == ')')//确保位置不能越界
            {
              dp[i] = dp[i+1] + 2;//找到了相匹配的右括号，当前数组中存储的最长长度是它后一个位置加2，后一个位置可能存储长度是0
              if(j+1<len)//这是连接两个子匹配的关键步骤
                dp[i] += dp[j+1];//在j的后面可能已经存在连续的匹配，要记得加上。dp[j+1]存储了以j+1开始的匹配
            }
            if(dp[i]>max)
              max = dp[i];//更新最长长度
          }
          
        }
        return max;
    }
};