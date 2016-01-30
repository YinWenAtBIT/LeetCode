class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows ==1)
            return s;
            
        int len = s.size();
        if(numRows == 2)
        {
            string s1, s2;
            for(int i=0; i< len; i++)
            if(i%2)
                s2 += s[i];
            else
                s1 += s[i];
            return string(s1+s2);
        }
        vector<string> res(numRows);
        int zag_len = numRows -2;
;
        
        int zigzag_len = numRows + zag_len;
        
        
        int remain;
        for(int i=0 ;i<len; i++)
        {
            remain = i%zigzag_len;
            if(remain < numRows)
                res[remain] += s[i];
            else
                res[zag_len-(remain - numRows)] += s[i];
        }
        string outcome;
        for(int i=0 ; i<numRows; i++)
            outcome+= res[i];
        return outcome;
    }
}; 