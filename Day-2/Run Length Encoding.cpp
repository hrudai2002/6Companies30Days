/* 
Problem - https://practice.geeksforgeeks.org/problems/run-length-encoding/1/# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=81d8aafb498ed838b59e6045538bfce8&pid=700243&user=sayihrudai 

*/

#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{ 
  string ans = "";
  int cnt = 1;
  src += "$";
  for(int i = 1; i < src.size(); ++i) {
      if(src[i] != src[i - 1]) {
          ans += src[i - 1] + to_string(cnt);
          cnt = 1;
      }
      else {
          cnt += 1;
      }
  }
  return ans;
  
  
}     
 
