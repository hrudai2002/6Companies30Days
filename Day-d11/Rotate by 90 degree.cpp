/* 

Problem - https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=48dc82be2fa5a3270d387974cec89e80&pid=701989&user=sayihrudai

*/

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    //  transpose 
    int m = matrix.size();
    int n = matrix[0].size();
    
    int row = m - 2;
    int col = n - 2; 
    while(col >= 0 and row >= 0) {
        int x1 = row;
        int y1 = n - 1;
        
        int x2 = n - 1;
        int y2 = col; 
        
        while(x1 < x2 and y2 < y1) {
            swap(matrix[x1][y1], matrix[x2][y2]);
            x1++, y1--; 
            x2--, y2++;
        }
        col--;
        row--;
    }
    
    row = m - 2; 
    col = n - 2;
    while(col >= 0 and row >= 0) {
        int x1 = row;
        int y1 = 0;
        
        int x2 = 0;
        int y2 = col; 
        
        while(x2 < x1 and y1 < y2) {
            swap(matrix[x1][y1], matrix[x2][y2]);
            x1--, y1++;
            x2++, y2--;
        }
        col--;
        row--;
    }
    
    int i = 0, j = m - 1;
    while(i < j) {
        for(int k = 0; k < n; ++k){
            swap(matrix[i][k], matrix[j][k]);
        }
        i++;
        j--;
    }
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
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends
