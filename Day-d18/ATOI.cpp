/* https://practice.geeksforgeeks.org/problems/implement-atoi/1/ */
class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int num = 0;
        int i = 0;
        bool neg = false;
        if(str[0] == '-') neg = true, i += 1;
        for(int j = i; j < str.size(); ++j) {
            char ch = str[j];
            if('0' <= ch and ch <= '9') {
                num = num*10 + (ch - '0');
            }
            else {
                return -1;
            }
        }
        if(neg) return -1 * num;
        return num;
    }
};
