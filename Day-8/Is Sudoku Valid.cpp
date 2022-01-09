/* 
Problem - https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/ 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=41f4dd5aa93a30230e3a706dbfe31189&pid=705293&user=sayihrudai

*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // row check
      bool ar[10];
      
      
      int row = mat.size();
      int col = mat[0].size();
      
      for(int i = 0; i < row; ++i){
          memset(ar,false,sizeof(ar));
          for(int j = 0; j < col; ++j){
              if(mat[i][j] > 0){
                  if(ar[mat[i][j]]) return 0;
                  ar[mat[i][j]]= true;
              }
          }
      }
      
      // col check
      
      
      for(int i = 0; i < row; ++i){
          memset(ar,false,sizeof(ar));
          for(int j = 0; j < col; ++j){
              if(mat[j][i] > 0){
                  if(ar[mat[j][i]]) return 0;
                  ar[mat[j][i]] = true;
              }
          }
      }
      
      // block check
      for(int i = 0; i < row; i += 3){
          for(int j = 0; j < col; j += 3){
              
             memset(ar,false,sizeof(ar));
             for(int l = i; l < i + 3; ++l){
                 for(int m = j; m < j + 3; ++m){
                     if(mat[l][m] > 0){
                         if(ar[mat[l][m]]) return 0;
                         ar[mat[l][m]] = true;
                             
                         
                     }
                 }
             }
          }
      }
      return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
