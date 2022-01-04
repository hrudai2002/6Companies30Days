/* 
Problem - Total Decoding Messages 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=4d8446239cb80dc3ab9d84e421635c7a&pid=705327&user=sayihrudai

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	   
		int CountWays(string str){
		    if(str.size() == 0 || str[0] == '0') return 0; 
		    if(str.size() == 1) return 1; 
		    int count1 = 1, count2 = 1; 
		    int m = 1000000007;
		    for(int i = 1; i < str.size(); ++i) {
		        int d = str[i] - '0';
		        int dd = d + 10*(str[i - 1] - '0'); 
		        int count = 0;
		        if(d > 0) count = (count%m + count2%m)%m; 
		        if(dd >= 10 and dd <= 26) count = (count%m + count1%m)%m; 
		        count1 = count2; 
		        count2 = count;
		    }
		    return count2;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
