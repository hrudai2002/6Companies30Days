/* 
Problem - https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=3a0c5762d78066f9afe99f4941f88169&pid=703804&user=sayihrudai
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ptr1 = 0;
        long long p = 1; 
        int res = 0;
        
        for(int i = 0; i < n; ++i) {
            p *= a[i]; 
            while(ptr1 < i and p >= k) {
                p /= a[ptr1];
                ptr1++;
            }
            if(p < k) {
                res += (i - ptr1 + 1);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
