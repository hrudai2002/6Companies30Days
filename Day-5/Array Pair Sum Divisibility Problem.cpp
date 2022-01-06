/* 
Problem - https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=941d23f58810bf903d28cdf6974ef7be&pid=704691&user=sayihrudai

*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> ar(k, 0);
        for(int i = 0; i < nums.size(); ++i) {
            ar[nums[i] % k]++;
        }
        if(k % 2) {
            if(ar[0] % 2) return false;
            for(int i = 1; i <= k/2; ++i) {
                if(ar[i] != ar[k - i]) return false;
            }
        }
        else {
            if((ar[0] % 2) or (ar[k/2] % 2)) return false; 
            for(int i = 1; i < k/2; ++i) {
                if(ar[i] != ar[k - i]) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
