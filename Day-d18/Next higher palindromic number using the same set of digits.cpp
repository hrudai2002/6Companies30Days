/* https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/ */
class Solution{
  public:
    string nextPalin(string str) { 
        if(str.size() <= 3) {
            return "-1";
        }
        
        int mid = str.size() / 2 - 1;
        string firsthalf = str.substr(0, mid + 1);
        string prevfirsthalf = firsthalf;
        
        next_permutation(firsthalf.begin(), firsthalf.end());
        if(firsthalf <= prevfirsthalf) {
            return "-1";
        }
        
        string res = firsthalf;
        if(str.size()%2 == 1) {
            res += str[mid + 1];
        }
        
        string secondhalf = firsthalf;
        reverse(secondhalf.begin(), secondhalf.end());
        
        res += secondhalf;
        
        return res;
        
    }
};
