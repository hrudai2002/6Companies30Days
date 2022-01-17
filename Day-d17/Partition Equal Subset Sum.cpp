/* Problem -  https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1 */

class Solution{
public:
    int dp[1001][1001] ;
    int subsetSum(int n,int arr[], int s) {
        if(n < 0) {
            if(s == 0) return 1;
            return 0;
        }
        if(s == 0) return 1;
        if(s < 0) return 0;
        if(dp[n][s] != -1) return dp[n][s];
        
        return dp[n][s] = subsetSum(n - 1, arr, s - arr[n]) || subsetSum(n - 1, arr, s);
    } 
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; ++i) sum += arr[i]; 
        if(sum & 1) return 0;
        dp[N][sum/2];
        memset(dp, -1, sizeof(dp));
        return subsetSum(N - 1, arr, sum/2);
    }
};
