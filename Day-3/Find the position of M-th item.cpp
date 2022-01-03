/* 
Problem - https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=ff2a87aa938df278039f2168d750de7f&pid=704216&user=sayihrudai

*/



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        int x = M % N;
        K -= 1;
        return x == 0 ? ((N + K) % N == 0? N : (N + K) % N) : ((x + K) % N == 0? N : (x + K) % N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
