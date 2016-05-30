class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if(!len)
            return false;
            
        for(int i=1; i<=len; i++)
        {
			string str1 = num.substr(0, i);
            if(str1.size()>1 && str1[0] == '0')
                return false;
            long long int first = atoll(str1.c_str());
            for(int j=i+1; j<=len; j++)
            {
                string str2 = num.substr(i, j-i);
                if(str2.size()>1 && str2[0] == '0')
                    break;
                long long int second = atoll(str2.c_str());
                if(dfs(num, j, first, second, 2))
                    return true;
            }
            
        }
        return false;
    }
    
    bool dfs(string &num, int start, long long int first, long long int second, int total)
    {
        int len = num.size();
        if(start >=len && total>2)
            return true;
        int max_bf = max(first, second);
        int count =0;
        while(max_bf)
        {
            count ++;
            max_bf /=10;
        }
        if(len -start<count)
            return false;
        for(int i = start+count; i<=len; i++)
        {
            string now = num.substr(start, i -start);
            if(now.size()>1 && now[0] == '0')
                return false;
            long long int third = atoll(now.c_str());
            if(first+second == third && dfs(num, i, second, third, total+1))
                return true;
            if(third>first +second)
                return false;
        }
        return false;
    }
};