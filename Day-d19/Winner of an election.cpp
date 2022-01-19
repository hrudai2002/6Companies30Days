/* https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/    */
vector<string> winner(string arr[],int n)
    {
       unordered_map<string, int> mp;
       string ans;
       int mx = 0;
       for(int i = 0; i < n; ++i) {
           string s = arr[i];
           mp[s] += 1;
       }
       
       for(int i = 0; i < n; ++i) {
           string s = arr[i];
           if(mp[s] > mx) {
               ans = s;
               mx = mp[s];
            }
            if(mp[s] == mx) {
                if(s < ans) {
                    ans = s;
                }
            }
           
       }
       return {ans, to_string(mx)};
    }
