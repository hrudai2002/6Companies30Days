/* 

Problem - https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=655a07702ceee5c3590eaead477a2cd8&pid=701264&user=sayihrudai

*/

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int top = 0, left = 0;
        int down = r, right = c; 
        
        while(top < down and left < right) {
            for(int i = left; i < right; ++i) {
                ans.push_back(matrix[top][i]);
                
            }
            top++;
            for(int i = top; i < down; ++i) {
                ans.push_back(matrix[i][right - 1]);
                
            }
            right--;
            
            if(top < down) {
                for(int i = right - 1; i >= left; i--) {
                    ans.push_back(matrix[down - 1][i]);
                    
                }
                down--;
            }
            if(left < right) {
                
                for(int i = down - 1; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                    
                }
                left++;
              }
          
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
