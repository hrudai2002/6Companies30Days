/* 
Problem - Squares in N*N Chessboard 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=11c97b8637d9a51fbbfb53616b5bfb9c&pid=704775&user=sayihrudai 
*/


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        // code here
        return (n*(n + 1)*(2*n + 1)) / 6;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
