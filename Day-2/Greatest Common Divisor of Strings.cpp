/* 
Problem - https://leetcode.com/problems/greatest-common-divisor-of-strings/
Submission - https://leetcode.com/submissions/detail/611203734/ 

*/

class Solution {
public:
    bool check(string A, string x) {
        string t = x; 
        while(t.size() <= A.size()) {
          if(t == A) return true; 
            t += x; 
            
        }
        return false;
    }
    string gcdOfStrings(string str1, string str2) {
        string x = "";
        string ans = "";
        for(char ch : str1) {
            x += ch; 
            if(check(str1, x) && check(str2, x))  {
                if(x.size() > ans.size()) {
                    ans = x; 
                }
            }
        }
        return ans;
    }
};
