/* 

Problem - https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=23220e022d6b3e768334eafa709fdb6d&pid=701276&user=sayihrudai

*/


 // } Driver Code Ends
class Solution
{
    public:
    int cnt;
    void maxArea(vector<vector<int>> &grid, int i, int j, int r, int c) {
        if(!((i >= 0 and i < r)  and (j >= 0 and j < c))) {
            return;
        }
        if(grid[i][j] == 0 || grid[i][j] == 2) {
            return;
        }
        grid[i][j] = 2;
        
        maxArea(grid, i, j + 1, r, c);
        maxArea(grid, i, j - 1, r, c);
        maxArea(grid, i + 1, j, r, c);
        maxArea(grid, i - 1, j, r, c);
        maxArea(grid, i + 1, j + 1, r, c);
        maxArea(grid, i + 1, j - 1, r, c);
        maxArea(grid, i - 1, j + 1, r, c);
        maxArea(grid, i - 1, j - 1, r, c);
        
        cnt += 1;
        
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int Max = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    cnt = 0; 
                    maxArea(grid, i, j, grid.size(), grid[0].size());
                    Max = max(Max, cnt);
                }
            }
        }
        return Max;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
