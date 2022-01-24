https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#
void findMax(string str, string &mx, int k, int pos) {
        if(k == 0) return;
        char maxm = str[pos];
        for(int i = pos + 1; i < str.size(); ++i) {
            if(maxm < str[i])
              maxm = str[i];
        }
        
        if(maxm != str[pos]) 
           k--; 
        
        for(int i = str.size() - 1; i >= pos; --i) {fd
            if(str[i] == maxm) {
                swap(str[i], str[pos]);
                if(str.compare(mx) > 0) 
                   mx = str;
                findMax(str, mx, k, pos + 1);
                swap(str[i], str[pos]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {  
       string mx = str;
       findMax(str, mx, k, 0);
       return mx;
       
    }
