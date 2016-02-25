class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        if(len <1)
            return;
        std::reverse(s.begin(), s.end());
        int pos =0;
        int start =0;
        while(pos < s.size())
        {
            if(s[pos] ==' ')
            {
                while(pos+1 <s.size() && s[pos+1] == ' ')
                    s.erase(s.begin()+pos);
                std::reverse(s.begin()+start, s.begin()+pos);
                start = pos +1;
            }
            pos++;
        }
        std::reverse(s.begin()+start, s.end());
		while(!s.empty() && s.back() ==' ')
            s.pop_back();
		while(!s.empty() && s.front() == ' ')
			s.assign(s.begin()+1, s.end());
    }
};