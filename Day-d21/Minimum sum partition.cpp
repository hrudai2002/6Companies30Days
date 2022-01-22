https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
int minDifference(int arr[], int n)  { 
      if(n == 1) return arr[0];
   int sum = 0;
    for(int i = 0; i < n; ++i) 
       sum += arr[i];
    int dp[100001] = {0};
    dp[0] = 1;
    for(int i = 0; i < n; ++i) 
      for(int j = sum; j >= arr[i]; --j)
          dp[j] = dp[j] || dp[j - arr[i]];

     int ans = INT_MAX; 
     for(int i = 1; i <= sum/2; ++i) {
         if(dp[i])
         ans = min(ans, sum - 2*i);
     }
     return ans;
} 
