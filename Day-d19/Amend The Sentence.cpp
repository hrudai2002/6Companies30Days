/*  https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1 */
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
