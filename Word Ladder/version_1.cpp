class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int mi = 0x7fffffff;
        int left =1, right =1;
        if(dfs(beginWord, endWord, wordList, left, right, mi))
            return mi;
        return 0;
    }
    bool dfs(string &begin, string &end, unordered_set<string>& wordList, int left, int right, int & mi)
    {
        int flag = false;
        if(match(begin, end))
        {
            flag = true;
            if(mi>left+right)
                mi = left+right;
        }
        if(flag)
            return true;

		unordered_set<string> remain;
		unordered_set<string> use;
        for(unordered_set<string>::iterator it = wordList.begin(); it !=wordList.end(); it++)
        {
            if(match(begin, *it))
            {
                if(match(*it, end))
                {
                    flag = true;
                    if(mi>left+right+1)
                        mi = left+right+1;
                    break;
                }
                else
                {
					remain = wordList;
                    string temp1 = *it;
					remain.erase(temp1);
                    string temp2;
                    for(unordered_set<string>::iterator it2 = remain.begin(); it2 != remain.end(); it2++)
                    {
                        if(match(*it2, end))
                        {
                            temp2 = *it2;
                            use = remain;
							use.erase(temp2);
                            if(dfs(temp1, temp2, use, left+1,  right+1, mi))
                                flag = true;
                        }
                    }
                }
            }
        }
        return flag;
        
    }
    bool match(const string &s1, const string &s2)
    {
        int len =s1.size();
        bool flag = true;
        for(int j=0; j<len; j++)
        {
            flag = true;
            for(int i=0; i<len; i++)
            {
                if(i == j)
                    continue;
                
                if(s1[i] != s2[i])
                    flag = false;
            }
            if(flag)
                break;
        }
        return flag;
    }
};
