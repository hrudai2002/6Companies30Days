/* 
Problem - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=79c55f687816744f0b7ecf615f8b339d&pid=701349&user=sayihrudai

*/

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *ar, int n, int k)
    {
        priority_queue<pair<int, int>> pq; 
        vector<int> ans; 
        for(int i = 0; i < k; ++i) {
            pq.push({ar[i], i});
        }
        ans.push_back(pq.top().first);
        int start = 0;
        for(int i = k; i < n; ++i) {
            while(!pq.empty() && pq.top().second <= start) {
                pq.pop();
            }
            start++; 
            pq.push({ar[i], i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
