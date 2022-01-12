/* 
Problem - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=fc526a5e5a26b0fbf9a533d6695a3ed6&pid=704140&user=sayihrudai
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int ar[], int N)  {
	    if(N == 1) return ar[0];
	    int sum = 0;
        for(int i = 0; i < N; ++i)
           sum += ar[i]; 
	    
	    vector<bool> dp(sum+1,0);
        dp[0] = 1;
        for(int i=0;i<N;i++) 
            for(int j=sum;j>=ar[i];j--)
                dp[j] = dp[j] || dp[j-ar[i]];
        
        
        
        int ans = INT_MAX;  
        for(int i = 1; i <= sum/2; ++i) {
            if(dp[i]) {
                ans = min(ans, sum - 2*i);
            }
        }
        return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
