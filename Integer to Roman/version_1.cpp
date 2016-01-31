class Solution {
public:
    string intToRoman(int num) {
        string roman[][10] = {  
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
            {"", "M", "MM", "MMM"}  
        };  
          
        string ret = "";  
        int digit = 0;  
        while (num != 0) {  
            int remain = num % 10;  
            ret = roman[digit][remain] + ret;  
            digit++;  
            num /= 10;  
        }  
          
        return ret;  
    }
};