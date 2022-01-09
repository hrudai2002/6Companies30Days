/* 
Problem - https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=df576fa8617af7b4bd3f011a5670f796&pid=701419&user=sayihrudai

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    
    long long countWays(int n)
    {    
         vector<long long> dp(n + 1, 0); 
         dp[0] = dp[1] = 1;
         for(int i = 2; i <= n; ++i) {
             dp[i] = dp[i - 2] + 1;
         }
         return dp[n];
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends
