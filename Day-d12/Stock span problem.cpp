/* 
Problem - https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=98f90bf83895151571a4bc2824fa0305&pid=701342&user=sayihrudai
*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> span; 
    //   span.push_back(1);
       stack<int> s; 
    //   s.push(0);
       for(int i = 0; i < n; ++i) {
           while(!s.empty() && price[s.top()] <= price[i]) 
                s.pop(); 
           if(s.empty()) {
               span.push_back(i + 1);
           }
           else {
               span.push_back(i - s.top());
           }
           
           s.push(i);
       }
       return span;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
