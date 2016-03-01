class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        bool flag = true;
        long long nume = numerator;
        long long deno = denominator;
        if(nume<0 && deno<0)
        {
            nume = 0-nume;
            deno = 0-deno;
        }
        else if(nume<0 || deno<0)
        {
            flag = false;
            if(nume<0 )
                nume = 0-nume;
            else
                deno = 0-deno;
        }
        
        
        
        long long integer = nume/deno;
        nume = nume%deno;
		res = itoa(integer);
		if(!flag)
            res.insert(res.begin(), '-');
        if(!nume)
            return res;
        
        if(res.empty())
            res.push_back('0');
        res.push_back('.');
        
        string frac = get_fraction(nume, deno);
        res += frac;

        return res;
        
    }
    string get_fraction(long long nume, long long deno)
    {
        string ret;
        string first;
        string second;
        
        while(nume !=0 && !check_most_simple(nume, deno))
        {
            nume *=10;
            if(nume >deno)
            {
                
                first.push_back('0'+nume/deno);
                nume = nume%deno;
            }
            else
            {
                first.push_back('0');
            }
            int com_divisor = get_common_divisor(nume, deno);
            nume /=com_divisor;
            deno /=com_divisor;
            
        }
        if(!nume)
            return first;
        
        int start = nume;
        do
        {
            nume *=10;
            if(nume >deno)
            {
                
                ret.push_back('0'+nume/deno);
                nume = nume%deno;
            }
            else
            {
                ret.push_back('0');
            }
        }while(nume !=0 && nume != start);
        if(nume == start)
        {
            ret.insert(ret.begin(), '(');
            ret.insert(ret.end(), ')');
        }
        return first+ret;
    }
    
    bool check_most_simple(long long nume, long long denu)
    {
        if(get_common_divisor(nume, denu) != 1)
            return false;
            
        while(nume < denu)
            nume *=10;
            
        if(get_common_divisor(nume, denu) !=1)
            return false;
        return true;
    }
    
    int get_common_divisor(long long small, long long big)
    {
        while(small)
        {
            int temp = big%small;
            big = small;
            small = temp;
        }
        return big;
    }
    
    string itoa(long long n)
    {
        string res;
        bool flag = true;
        if(n==0)
        {
            res.push_back('0');
            return res;
        }
        if(n<0)
        {
            flag=false;
            n = 0-n;
        }
        while(n)
        {
            int get = n%10;
            res = static_cast<char>('0'+get)+res;
            n = n/10;
        }
        if(!flag)
            res = '-'+res;
        
        return res;
        
    }
};