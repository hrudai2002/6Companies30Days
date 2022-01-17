/* https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/ */

class Solution
{
  public:
    const int m = 1000000007;
    long long int power(long long int a, long long int b) {
        if(b == 1) return a % m; 
        else if(b & 1) return ((a % m) * (power(a, b / 2) % m) * ( power(a, b / 2) % m))%m;
        else return ((power(a, b / 2) % m)  * (power(a, b / 2) % m))%m;
    }
    int kvowelwords(int N, int K) {
        long long int dp[N + 1][K + 1] = {0};
        long long int sum = 1;
        long long int i, j;
        for(i = 1; i <= N; ++i) {
            dp[i][0] = ((sum % m) * (21 % m)) % m;
            sum = dp[i][0];
            for(j = 1; j <= K; ++j) {
                if(j > i) 
                  dp[i][j] = 0;
                else if(i == j) 
                   dp[i][j] = power(5, i);
                else 
                   dp[i][j] = ((dp[i - 1][j - 1] % m) * (5 % m)) % m;
                
                sum = ((sum % m) + (dp[i][j] % m)) % m;
            }
            
        }
        
        return sum;
    }
};
