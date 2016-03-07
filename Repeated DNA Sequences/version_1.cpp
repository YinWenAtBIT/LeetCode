class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int len = s.size();
        if(len<10)
            return res;
        
        unordered_map<string, int> seq;
        for(int i=0; i<len-9; i++)
        {
            string sub = s.substr(i, 10);
            seq[sub]++;
            if(seq[sub] == 2)
                res.push_back(sub);
        }
        return res;
    }
};