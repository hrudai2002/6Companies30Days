/* 

Problem - https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=4e35009985827b9457091c9e4920d86b&pid=701199&user=sayihrudai


*/


#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> ans;
    vector<string> phone{
      "0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"  
    };
    void solve(int a[], int i, int N, string s) {
        if(i == N - 1) {
            for(auto x : phone[a[i]]) {
                ans.push_back(s + x);
            }
        }
        else {
            string str = phone[a[i]];
            for(int j = 0; j < str.size(); ++j) {
                solve(a, i + 1, N, s + str[j]);
            }
        }
    }
    vector<string> possibleWords(int a[], int N)
    { 
      solve(a, 0, N, "");
      return ans;  
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
