/* 

Problem - https://practice.geeksforgeeks.org/problems/alien-dictionary/1/# 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=a225261bde0ff4a0d0a8266f4b4c7d3f&pid=700494&user=sayihrudai

*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> mp;
        for(int i = 1; i < N; ++i) {
            string s1 = dict[i - 1];
            string s2 = dict[i];
            
            for(int i = 0; i < min(s1.size(), s2.size()); i++) {
                if(s1[i] != s2[i]) {
                     mp[s1[i]].push_back(s2[i]);
                     indegree[s2[i]]++;
                     if(indegree.find(s1[i]) == indegree.end())  indegree[s1[i]] = 0; 
                     break;
                }
            }
        }
        queue<char> q;
        for(auto x : indegree) {
            if(x.second == 0) q.push(x.first);
        }
        
        string ans = "";
        while(!q.empty()) {
            char node = q.front();
            q.pop();
            ans += node;
            for(auto x : mp[node]) {
                indegree[x] -= 1;
                if(indegree[x] == 0) q.push(x);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
