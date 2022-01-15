/* 

Prolem - https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/ 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=8da6af7230701a71e24dc853f1a74823&pid=704560&user=sayihrudai

*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int minSteps(int D){
       int sum = 0, steps = 0;
       while(true) {
           sum += steps; 
           steps += 1;
           
           if(sum == D) {
               return steps - 1;
           }
           if(sum > D and (sum - D) % 2 == 0) {
               return steps - 1;
           }
       }
    //   return steps - 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
