/* 

Problem - https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=bef0a9b3735a7d7e9a273d60803bf1b0&pid=707042&user=sayihrudai

*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        priority_queue<pair<int, int>> p; 
        vector<int> ans; 
        for(int i = 0; i < k; ++i) {
            p.push({arr[i], i});
        }
        ans.push_back(p.top().first); 
        int start = 0;
        for(int i = k; i < n; ++i) {
            while(!p.empty() && p.top().second <= start) {
                p.pop();
            }
            start += 1;
            p.push({arr[i], i});
            ans.push_back(p.top().first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
