/* 
Problem - https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=6cf5e2e5ac52bf498a10b0dc6526d50f&pid=705474&user=sayihrudai

*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        if(L1[0]>R2[0] || L2[0]>R1[0])
            return false;
        //If one rectangle is above the other
        if(L1[1]<R2[1] || L2[1]<R1[1])
            return false;
        return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
