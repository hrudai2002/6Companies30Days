/* https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/    */
string amendSentence (string s)
    {
        s += "$";
        string ans = "";
        string res = "";
        for(int i = 0; i < s.size(); ++i) {
            if(('A' <= s[i] and s[i] <= 'Z') or s[i] == '$') {
                if(res.size() > 0){
                    if(s[i] != '$')
                    ans += res + " ";
                    else
                    ans += res;
                }
                res = tolower(s[i]);
            }
            else {
                res += s[i];
            }
        }
        return ans;
        
    }
