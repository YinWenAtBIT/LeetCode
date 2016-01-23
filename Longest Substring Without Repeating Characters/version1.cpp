class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        
        int length = s.size();
        set<char> container;
        int max=1;
        int sizetemp;
        int last= 0;
        for(int i=0; i<length; i++)
        {
            auto res = container.insert(s[i]);
            if(!res.second)
            {
                sizetemp = container.size();
                if(sizetemp > max)
                    max = sizetemp;
                container.clear();
                
                last +=1;
                container.insert(s[last]);
                i = last;
            }

        }
        sizetemp = container.size();
        if(sizetemp > max)
            max = sizetemp;    
        return max;
    }
};