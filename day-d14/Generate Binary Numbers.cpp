/* 

Problem - https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=bc52242938375f8da021b12d5b7b7581&pid=701347&user=sayihrudai


*/

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string bin(int n) {
    string ans = "";
    while(n > 0) {
        ans = to_string(n % 2) + ans;
        n /= 2;
    }
    return ans;
}
vector<string> generate(int N)
{   
    vector<string> ans;
	for(int i = 1; i <= N; ++i) {
	    ans.push_back(bin(i));
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
