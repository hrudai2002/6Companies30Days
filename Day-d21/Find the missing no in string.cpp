https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/#
int sto(string s) {
    int num = 0;
    for(char ch : s) {
        num = num*10 + (ch - '0');
    }
    return num;
}
int missingNumber(const string& str)
{   
    for(int len = 1; len <= 6; ++len) {
        int prev = 0;
        int l = len;
        int i = 0;
        while(i < str.size() && l--)
            prev = prev*10 + (str[i++] - '0');
        int j = i, mis, cnt = 0;
        bool flag = 0;
        string temp = "";
        while(j < str.size()) {
            temp += str[j++];
            if(prev + 1 == sto(temp)) {
                prev = stoi(temp);
                temp = "";
            }
            else if(prev + 2 == sto(temp)) {
                cnt += 1;
                mis = prev + 1;
                prev = sto(temp);
                temp = "";
            }
            else if(prev < sto(temp))
               flag = 1;
        }
        if(cnt == 1 && flag == 0) {
            return mis;
        }
    }
    return -1;
}
