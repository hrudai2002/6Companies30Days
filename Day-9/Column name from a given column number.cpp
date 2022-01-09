/*
Problem - https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/#
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=dad840745ef4d561e611a467b98af972&pid=702959&user=sayihrudai
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long int
class Solution{
    public:
    string colName (ll n)
    {
        string s = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";
        if(n < 27) {
            ans += s[n];
            return ans;
        }
        while(n > 26) {
            ll Q = n / 26;
            ll r = n % 26;
            ans = s[r] + ans; 
            
            if(r == 0) Q--;
            if(Q <= 26)
              ans = s[Q] + ans; 
            n = Q; 
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
