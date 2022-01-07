/* 
Problem - https://leetcode.com/problems/longest-mountain-in-array/submissions/ 
Submission - https://leetcode.com/submissions/detail/614892447/

*/

class Solution {
public:
    int longestMountain(vector<int>& ar) {
        int maxlen = 0, n = ar.size(); 
        for(int i = 0; i < n - 1; ++i) {
            if(ar[i] < ar[i + 1]) {
                int j = i;
                bool flag1 = false, flag2 = false;
                while(i < n - 1 && ar[i] < ar[i + 1])
                      i++, flag1 = true; 
                while(i < n - 1 && ar[i] > ar[i + 1])
                      i++, flag2 = true; 
                
                if(flag1 && flag2)
                maxlen = max(maxlen, i - j + 1);
                i--;
            }
        }
        return maxlen;
    }
};
