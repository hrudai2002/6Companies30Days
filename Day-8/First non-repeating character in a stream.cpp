/* 
Problem - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=b3e9fd036c26765fb4bdd2c21ad231c3&pid=705333&user=sayihrudai

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		    vector<int> ar(26, 0);
		    string ans = "";
		    int count = 0;
		    for(int i = 0; i < A.size(); ++i) {
		        ar[A[i] - 'a'] += 1;
		        if(ar[A[i] - 'a'] == 2) count += 1;
		        if(count == 26) {
		            ans += "#";
		        }
		        else {
		            pq.push({ar[A[i] - 'a'], i}); 
		            while(!pq.empty() and (ar[A[pq.top().second] - 'a'] != 1)) {
    		            pq.pop();
    		        }
    		        if(pq.empty()) 
    		          ans += "#";
    		        
    		        else 
    		          ans += A[pq.top().second];
		        }
		        
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
