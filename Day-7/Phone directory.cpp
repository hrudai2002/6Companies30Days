/* 
Problem - https://practice.geeksforgeeks.org/problems/phone-directory4628/1/ 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=b2dba92f5d112720abc52daca5ba9330&pid=705602&user=sayihrudai

*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    Solution *children[26];
    vector<vector<string>> ans;
    unordered_map<Solution*, vector<string>> mp;
    bool isEndOfWord;
    
    void Print(Solution *x) {
        vector<string> res;
        unordered_map<string, int> r;
        for(auto i : mp[x]) {
             r[i] += 1;
             if(r[i] == 1)
             res.push_back(i);
            }
        sort(res.begin(), res.end());
        ans.push_back(res);
    }


    Solution *getNode()
    {
        Solution *pNode =  new Solution;
    
        pNode->isEndOfWord = false;
    
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    
        return pNode;
    }


    void insert(Solution *root, string key)
    {
        Solution *pCrawl = root;
    
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = getNode();
            mp[pCrawl->children[index]].push_back(key);
    
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    void search(Solution *root, string key)
    {
        Solution *pCrawl = root;
    
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index]) {
                for(int j = i; j < key.length(); ++j) {
                    ans.push_back({"0"});
                }
                return;
            }
                
            
            Print(pCrawl->children[index]);
            pCrawl = pCrawl->children[index];
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {   
        Solution *root = getNode();
        for (int i = 0; i < n; i++)
        insert(root, contact[i]);
        
        search(root, s);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
