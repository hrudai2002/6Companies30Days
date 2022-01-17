/* Problem - https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/ */ 
class Solution
{
    public:
    vector<string>ret;
    void fill(int a,int b,string s){
        if(a==0 and b==0){ret.push_back(s);return;}
        if(a>=0)fill(a-1,b,s+"(");
        if(b>a)fill(a,b-1,s+")");
    }
    vector<string> AllParenthesis(int n) 
    {
        fill(n,n,"");
        return ret;
    }
};
