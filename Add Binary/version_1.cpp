class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        if(len_a<len_b)
        {
            swap(a,b);
            swap(len_a, len_b);
        }
        int carry = 0;
        int temp;
        while(len_a && len_b)
        {
            temp = (a[len_a-1] -'0') + (b[len_b-1] -'0' +carry);
            carry = temp/2;
            temp = temp%2;
            a[len_a-1] = temp+'0';
            
            len_a--;
            len_b--;
        }
        if(len_a && carry)
        {
            while(len_a && carry)
            {
                temp = (a[len_a-1] -'0') +carry;
                carry = temp/2;
                temp = temp%2;   
                a[len_a-1] = temp+'0';
                len_a --;
            }
        }
        if(carry)
            a.insert(0, 1, '1');
        int start_pos=0;
        if(!a.size())
            return string("0");
        while(a[start_pos] =='0' && start_pos<a.size()-1)
            start_pos++;
        return a.substr(start_pos);
    
    }
};