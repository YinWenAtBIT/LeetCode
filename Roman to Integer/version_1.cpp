class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1, dict['i'] = 1;
        dict['V'] = 5, dict['v'] = 5;
        dict['X'] = 10, dict['x'] = 10;
        dict['L'] = 50, dict['l'] = 50;
        dict['C'] = 100, dict['c'] = 100;
        dict['D'] = 500, dict['d'] = 500;
        dict['M'] = 1000, dict['m'] = 1000;
        
        int len = s.size();
        int sum  = dict[s[0]];
        for(int i=1; i<len; i++)
        {
            if(dict[s[i]]<=dict[s[i-1]])
                sum += dict[s[i]];
            else
                sum += dict[s[i]] - 2*dict[s[i-1]];
        }
        return sum;
    }
};