class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows ==1)
            return s;
            
        int len = s.size();
        vector<string> res(numRows);
        int zag_len = numRows -2;
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