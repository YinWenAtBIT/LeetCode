class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> res;
        vector<string> temp;
        if(differ(beginWord, endWord)<=1)
        {
            temp.push_back(beginWord);
            temp.push_back(endWord);
            res.push_back(temp);
            return res;
        }
        
        
        unordered_map<string, unordered_set<string>> path;
		unordered_set<string> last_word;
		unordered_set<string> last_use;
		bool flag = false;
        string none;
		path[beginWord].insert(none);
        queue<pair<string, int>> q;
        q.push(pair<string, int> (beginWord, 1));
        wordList.erase(beginWord);
        string str, nxt;
        int cntStep;
		int lastStep =0;
        int minStep;
        while (!q.empty()) {
            str = q.front().first;
            cntStep = q.front().second;
            if(flag && cntStep >= minStep)
                break;
			if(lastStep != cntStep)
			{
				lastStep =cntStep;
				for(auto it = last_use.begin(); it != last_use.end(); it++)
					wordList.erase(*it);
				last_use.clear();
			}
            q.pop();

            for (int i = 0; i < str.length(); i++)
                for (char j = 'a'; j <= 'z'; j++) {
                    if (str[i] == j)
                        continue;
                    nxt = str;
                    nxt[i] = j;
                    if(nxt == endWord)
                    {
                        flag = true;
                        minStep = cntStep+1;
						if(last_word.count(str))
							break;
						last_word.insert(str);
                        deque<string> strpath;
						strpath.push_front(endWord);
                        strpath.push_front(str);
						dfs_insert(res, strpath, path, str);
                    }
                    else if (wordList.count(nxt)) {
                        last_use.insert(nxt);
						path[nxt].insert(str);
                        q.push(pair<string, int> (nxt, cntStep+1));
                    }
                }
        }
        return res;
    }
    
    int differ(string &s1, string &s2)
    {
        int len = s1.size();
        int count =0;
        for(int i=0; i<len; i++)
            if(s1[i] != s2[i])
                count++;
        return count;
    }
	void dfs_insert(vector<vector<string>> &res, deque<string> &strpath, unordered_map<string, unordered_set<string>> &path, string & key)
	{
		unordered_set<string> before = path[key];
		int len = before.size();
		for(auto it = before.begin(); it != before.end(); it++)
		{
			string now_key = *it;
			if(now_key.empty())
			{
				vector<string> temp(strpath.begin(), strpath.end());
				res.push_back(temp);
			}
			else
			{
				strpath.push_front(now_key);
				dfs_insert(res, strpath, path, now_key);
				strpath.pop_front();
			}
		}
	}

};