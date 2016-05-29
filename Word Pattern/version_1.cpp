class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pa_len = pattern.size();
        if(!pa_len)
            return false;
        int len = str.size();
        unordered_map<char, string> ch_to_word;
        unordered_map<string, char> word_to_ch;
        int start =0;
        int ch_cur=0;
        while(start<len)
        {
            string now = get_word(str, start);
            ch_to_word[pattern[ch_cur]] = now;
            if(word_to_ch.count(now))
            {
                if(word_to_ch[now] != pattern[ch_cur])
                    return false;
            }
            else
                word_to_ch[now] = pattern[ch_cur];
            
            ch_cur++;
        }
        return ch_to_word.size() == word_to_ch.size() && ch_cur == pa_len;
    }
    string get_word(string &str, int &start)
    {
        int len = str.size();
        int temp=start;
        while(start<len && str[start] !=' ')
            start++;
        string res(str.begin()+temp, str.begin()+start);
        
        while(start<len && str[start] ==' ')
            start++;
        return res;
    }
};