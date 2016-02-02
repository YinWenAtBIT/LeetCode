class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.size();
        if(!len || digits.find("0") != string::npos || digits.find("1")!= string::npos)
            return res;
        
        string emp;
        res.push_back(emp);
        vector<string> temp1;
        vector<string> temp2;
        for(int i=0; i<len; i++)
        {
            string reflect = digit_to_character(digits[i]);
            int re_len = reflect.size();
            temp1.clear();
            for(int j=0; j<re_len; j++)
            {
                temp2 = append_character(res, reflect[j]);
                temp1.insert(temp1.end(), temp2.begin(), temp2.end());
            }
            res = temp1;
        }
        return res;
    }
    
    vector<string> append_character(vector<string> &origin, char c)
    {
        vector<string> new_one = origin;
        int len = new_one.size();
        for(int i=0; i<len; i++)
            new_one[i] += c;
        return new_one;
    }
    
    string digit_to_character(char c)
    {
        switch(c)
        {
            case '2': return string("abc");
            case '3': return string("def");
            case '4': return string("ghi");
            case '5': return string("jkl");
            case '6': return string("mno");
            case '7': return string("pqrs");
            case '8': return string("tuv");
            case '9': return string("wxyz");
        }
    }
};