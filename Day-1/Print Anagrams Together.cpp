/* 

Problem - https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=085e026e74df58abf17a11fefb3a3a5a&pid=701966&user=sayihrudai 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string, string> _sort; 
        for(string s : string_list) {
            string x = s; 
            sort(x.begin(), x.end()); 
            _sort[s] = x;
        }
        unordered_map<string, vector<string>> grp; 
        unordered_map<string, bool> check;
        for(string s : string_list) {
            grp[_sort[s]].push_back(s);
            check[_sort[s]] = true;
        }
       
        vector<vector<string>> ans; 
        for(string s : string_list) {
            if(check[_sort[s]]) {
                check[_sort[s]] = false; 
                ans.push_back(grp[_sort[s]]);
            }
        }
        return ans;
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
