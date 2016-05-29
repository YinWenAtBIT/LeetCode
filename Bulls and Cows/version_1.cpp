class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int len = secret.size();
        if(!len)
            return res;
        
        int count_right = 0;
        for(int i=0; i<len; i++)
        {
            if(secret[i] == guess[i])
                count_right++;
            
        }
        
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
        int i=0, j=0;
        int count =0;
        while(i<len &&j<len)
        {
            if(secret[i] == guess[j])
            {
                count++;
                i++,j++;
            }
            else if(secret[i]<guess[j])
                i++;
            else
                j++;
        }
        int remain = count-count_right;
        res+=to_string(count_right) +"A";
        res+=to_string(remain)+"B";
        return res;
    }
};