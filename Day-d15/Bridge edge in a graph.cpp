/* 

Problem - https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=a5fbda062f7b46106e00fb544b06580b&pid=700463&user=sayihrudai

*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        for(int i = 0; i < adj[c].size(); ++i) {
            if(adj[c][i] == d) {
                adj[c].erase(adj[c].begin() + i);
                break;
            }
        }
        
        for(int i = 0; i < adj[d].size(); ++i) {
            if(adj[d][i] == c) {
                adj[d].erase(adj[d].begin() + i);
            }
        }
       
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(c);
        vis[c] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto x : adj[node]) {
                if(vis[x] == false) {
                     q.push(x);
                     vis[x] = true; 
                }
               
            }
        }
        if(vis[d]) return 0;
        return 1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
