/* https://leetcode.com/problems/string-to-integer-atoi/*/
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        bool neg = false, trigger = false;
        int i = 0;
        int integer = 214748364;
        while(i < s.size() and s[i] == ' ')
             i += 1; 
        if(i == s.size()) return num;
        if(s[i] == '-'){
            neg = true;
            i += 1;
        }
        else if(s[i] == '+') {
            i += 1;
        }
        for(int p = i; p < s.size(); ++p) {
            if('0' <= s[p] and s[p] <= '9') {
                 int x = (s[p] - '0');
                 if(neg) {
                     if(num > integer)  {
                         num = integer*10 + 7;
                         trigger = true;
                     }
                     else if(num == integer) {
                         if(x <= 7) num = num*10 + x;
                         else num = integer*10 + 7, trigger = true;
                     }
                     else 
                        num = num*10 + x;
                     
                 }
                else {
                    if(num > integer)  {
                         num = integer*10 + 7;
                         
                     }
                     else if(num == integer) {
                         if(x <= 7) num = num*10 + x;
                         else num = integer*10 + 7;
                     }
                     else 
                        num = num*10 + x;
                }
                 
            }
            else {
                if(neg){
                    if(trigger)
                     return (num * -1) - 1;
                    return -1 * num;
                }
                return num;
            }
        }
        if(neg) {
            if(trigger)
                 return (num * -1) - 1;
            return -1 * num;
        }
        return num;
    }
};
