class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
        // Note: The Solution object is instantiated only once.  
        map<string, int> words;  
        map<string, int> cur;  
        int wordNum = L.size();  
        for(int i = 0; i < wordNum; i++)  
            words[L[i]]++;  
        int wordlen = L[0].size();  
        vector<int> res; 
        int s_len = S.size();
        if(s_len < wordlen*wordNum)
            return res;  
            
        int left =0;
        int count = 0;
        for(int i=0; i<wordlen; i++)
        {
            count =0; left = i;
            cur.clear();
            for(int j=i; j<= s_len -wordlen; j+= wordlen)
            {
                string sub = S.substr(j, wordlen);
                if(words.find(sub) != words.end())
                {
                    ++cur[sub];
                    count++;
                    if(cur[sub] >words[sub])
                    {
                        while(1)
                        {
                            string before = S.substr(left, wordlen);
                            --cur[before];
                            count--;
                            left += wordlen;
                            if(before == sub)
                                break;
                        }
                    }
                    if(count == wordNum)
                        res.push_back(left);
                        
                }
                else
                {
                    cur.clear();
                    left =j + wordlen;
                    count =0;
                }
            }
        }
        
        return res;
              
    }
};