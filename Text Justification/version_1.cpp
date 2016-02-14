class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int len = words.size();
        if(!len || !maxWidth)
        {
            res.resize(1);
            return res;
        }
        int pos =0;
        int start_pos =0;
        int wordlen =0;
        int total_len =0;
        bool right_match = false;
        while(pos<len)
        {
            start_pos = pos;
            right_match = false;
            total_len = 0;
            while(total_len <maxWidth && pos<len)
            {
                int right_len =  words[pos].size();
                if(total_len+right_len <maxWidth)
                {
                    total_len +=right_len +1;
                    pos++;
                }
                else if(total_len+right_len == maxWidth)
                {
                    total_len +=right_len;
                    right_match = true;
                    pos++;
                    break;
                }
                else
                    break;
            }
            
            int word_num = pos - start_pos;
            if(!word_num)
                break;
            int blank_len = right_match? word_num-1:word_num+maxWidth-total_len;
            int blank_num = word_num -1;
            string temp;
            if(pos == len)
            {
                for(int i=0; i<word_num-1; i++)
                {
                    temp += words[start_pos+i];
                    temp += ' ';
                }
                temp+= words[start_pos + word_num -1];
                int remain_blank = maxWidth - temp.size();
                temp.insert(temp.end(), remain_blank, ' ');
                res.push_back(temp);
            }
            else if(!blank_num)
            {
                temp+= words[start_pos + word_num -1];
                int remain_blank = maxWidth - temp.size();
                temp.insert(temp.end(), remain_blank, ' ');
                res.push_back(temp);
            }
            else
            {
                for(int i=0; i<blank_num; i++)
                {
                    temp+=words[start_pos+i];
                    int right_blank = blank_len/(blank_num-i);
                    if(blank_len %(blank_num-i))
                        right_blank +=1;
                    temp.insert(temp.end(), right_blank, ' ');
                    blank_len -= right_blank;
                }
                temp += words[start_pos + word_num -1];
                res.push_back(temp);
            }
            
        }
        
        return res;
    }
};