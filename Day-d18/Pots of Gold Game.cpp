/* Problem - https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/ */ 


  int dp[1001][1001];
  int solve(int i, int j, vector<int> A) {
      if(i > j) return 0;
      if(dp[i][j] != -1) return dp[i][j];

      int l = A[i] + min(solve(i + 2, j, A), solve(i + 1, j - 1, A));
      int r = A[j] + min(solve(i + 1, j - 1, A), solve(i, j - 2, A));

      return dp[i][j] = max(l, r);
  }
  int maxCoins(vector<int>&A,int n)
  {
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    return solve(0, n - 1, A);
  }
};
