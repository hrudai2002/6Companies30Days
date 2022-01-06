/* 
Problem - https://leetcode.com/problems/minimum-size-subarray-sum/ 
Submission - https://leetcode.com/submissions/detail/614236680/

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int s = 0, minlen = INT_MAX, p = 0; 
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            s += a[i]; 
            while(s >= target and p <= i) {
                minlen = min(minlen, i - p + 1);
                s -= a[p]; 
                p++;
            }
        }
        if(minlen == INT_MAX) return 0;
        return minlen;
    }
};
