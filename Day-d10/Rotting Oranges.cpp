/* 
Problem - https://leetcode.com/problems/rotting-oranges/
Submission - https://leetcode.com/submissions/detail/618147800/

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int, int>> q;
       int fresh = 0, ans = 0;
       for(int i = 0; i < grid.size(); ++i) {
           for(int j = 0; j < grid[0].size(); ++j) {
                 if(grid[i][j] == 2) q.push({i, j});
                 if(grid[i][j] == 1) fresh += 1;
           }
       }
       if(fresh == 0) return 0;
       if(q.empty()) return -1;
        
       q.push({-1, -1});
       while(!q.empty()) {
           vector<vector<bool>> dp(grid.size(), vector<bool>(grid[0].size(), true)); 
           int x = q.front().first;
           int y = q.front().second;
           q.pop();
           
           if(x - 1 >= 0 and dp[x - 1][y] and grid[x - 1][y] == 1) {
               grid[x - 1][y] = 2; 
               dp[x - 1][y] = false;
               q.push({x - 1, y});
           }
           
           if(x + 1 < grid.size() and dp[x + 1][y] and grid[x + 1][y] == 1) {
               grid[x + 1][y] = 2; 
               dp[x + 1][y] = false;
               q.push({x + 1, y});
           }
           
           if(y - 1 >= 0 and dp[x][y - 1] and grid[x][y - 1] == 1) {
               grid[x][y - 1] = 2; 
               dp[x][y - 1] = false; 
               q.push({x, y - 1});
           }
           
           if(y + 1 < grid[0].size() and dp[x][y + 1] and grid[x][y + 1] == 1) {
               grid[x][y + 1] = 2; 
               dp[x][y + 1] = false; 
               q.push({x, y + 1});
           }
           
           if(q.front().first == -1) {
               if(q.size() == 1) q.pop();
               else {
                   q.pop();
                   q.push({-1, -1}); 
                   ans += 1;
               }
               
           }
           
        }
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};
