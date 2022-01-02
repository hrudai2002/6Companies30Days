/* 
Problem - https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=4e761fd54395e889255d5947a75774a4&pid=703093&user=sayihrudai

*/

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/

	ull getNthUglyNo(int n) {
	    ull dp[n + 1] = {0}; 
	    ull mn; 
	    ull ptr1 = 1, ptr2 = 1, ptr3 = 1; 
	    dp[1] = 1; 
	    for(int i = 2; i <= n; ++i) {
	        ull num1 = dp[ptr1]*2; 
	        ull num2 = dp[ptr2]*3; 
	        ull num3 = dp[ptr3]*5; 
	        
	        mn = min(num1, min(num2, num3));
	        dp[i] = mn; 
	        
	        if(mn == num1) 
	          ptr1 += 1; 
	          
	        if(mn == num2) 
	          ptr2 += 1; 
	        
	        if(mn == num3)
	          ptr3 += 1;
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
