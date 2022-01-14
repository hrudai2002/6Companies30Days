/* 
Problem - https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=a525b9c6841f0d35ac7b5930b9a9fb09&pid=702139&user=sayihrudai

*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        set<vector<int>> s; 
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        for(int i = 0; i < n - 3; ++i) {
            for(int j = i + 1; j < n - 2; ++j) {
                int l = j + 1;
                int r = n - 1; 
                while(l < r) {
                    if((arr[i] + arr[j] + arr[l] + arr[r]) == k) {
                        s.insert({arr[i], arr[j], arr[l], arr[r]});
                        l++;
                    }
                    else if((arr[i] + arr[j] + arr[l] + arr[r]) < k) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i : s) {
            ans.push_back(i);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
