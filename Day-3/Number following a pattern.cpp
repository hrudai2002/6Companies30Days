/* 
Problem - https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=24965bdc72011de8ce628ffb41bf274e&pid=703607&user=sayihrudai

*/

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
         if(S.size() == 1) {
             if(S[0] == 'D') return "21";
             return "12";
         }
         string ans = ""; 
         int n = S.size(); 
         int i = 1, r = 0; 
         if(S[0] == 'I') {
             ans += "1"; 
             i += 1;
         }
         for(int j = 0; j < S.length(); ++j) {
             if(S.length() - 1 == j) {
                 if(S[j] == 'I') {
                     ans += to_string(i);
                 }
             }
             else if(S[j] == 'D') {
                 string x = to_string(i);
                 i += 1;
                 while(j < S.length() and S[j] == 'D') {
                     x += to_string(i); 
                     j++;
                     i++; 
                 }
                 j -= 1;
                 reverse(x.begin(), x.end());
                 ans += x;
             }
             else if(S[j] == 'I' and S[j + 1] == 'I') {
                 ans += to_string(i);
                 i += 1;
             }
             else if(S[j] == 'I' and S[j + 1] == 'D') {
                 string x = to_string(i);
                 i += 1;
                 j += 1;
                 while(j < S.length() and S[j] == 'D') {
                     x += to_string(i);
                     i += 1;
                     j += 1;
                 }
                 j -= 1; 
                 reverse(x.begin(), x.end());
                 ans += x;
             }
         }
         return ans;
          
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
