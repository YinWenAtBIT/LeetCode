class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
        // Note: The Solution object is instantiated only once.  
        map<string, int> words;  
        map<string, int> cur;  
        int wordNum = L.size();  
        for(int i = 0; i < wordNum; i++)  
            words[L[i]]++;  
        int wordLen = L[0].size();  
        vector<int> res;  
        //if(S.size() < wordLen*wordNum)return res;  
        for(int i = 0; i <= (int)S.size()-wordLen*wordNum; i++)  
        {  
            cur.clear();  
            int j;  
            for(j = 0; j < wordNum; j++)  
            {  
                string word = S.substr(i+j*wordLen, wordLen);  
                if(words.find(word) == words.end())  
                    break;  
                cur[word]++;  
                if(cur[word]>words[word])  
                    break;  
            }  
            if(j == wordNum)  
                res.push_back(i);  
        }  
        return res;  
              
    }
};