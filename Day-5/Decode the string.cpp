/* 
Problem - https://practice.geeksforgeeks.org/problems/decode-the-string2444/1# 
submission - https://practice.geeksforgeeks.org/viewSol.php?subId=e91b576a6ce951c323daf85a7e80d79d&pid=705287&user=sayihrudai
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    pair<string, int> Rs(string s, int n, int itr) {
    string ans = ""; 
    for(int i = itr; i < n; ++i) {
            if(s[i] == ']') return {ans, i};
            else if(isalpha(s[i])) {
                ans += s[i];
            }
            else if(isdigit(s[i])) {
                int num = 0; 
                while(isdigit(s[i])) {
                    num = num*10 + (s[i] - '0'); 
                    i += 1;
                }
                pair<string, int> x = Rs(s, n, i + 1); 
                i = x.second; 
                for(int j = 0; j < num; ++j) 
                    ans = ans + x.first;
            }
        }
        return {ans, itr};
    }
    
    string decodedString(string s){
        pair<string, int> ans = Rs(s, s.size(), 0);  
        return ans.first;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
