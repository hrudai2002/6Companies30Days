https://practice.geeksforgeeks.org/problems/word-search/1/
bool ans = false;
   int rowIdx[4] = {-1,1,0,0};
   int colIdx[4] = {0,0,-1,1};
   bool isSafe(vector<vector<char>>& board,vector<vector<bool>>& visited, int i, int j , int r, int c, string word,int idx) {
       if(i>=0 && j>=0 && i<r && j<c && !visited[i][j] && idx < word.length() && board[i][j] == word[idx] ) {
           return true;
       }
       return false;
   }
   
   void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,
                   int i,int j,int r,int c,
                   string word,int v) {
       if(v>=word.length())
           {ans = true;return;}

       for(int k=0;k<4;k++){
           if(isSafe(board,visited,i+rowIdx[k],j+colIdx[k],r,c,word,v)){
               visited[i+rowIdx[k]][j+colIdx[k]] = true;
               dfs(board,visited,i+rowIdx[k],j+colIdx[k],r,c,word,v+1);
           }
       }
       visited[i][j]=false;
   }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
         int r=board.size();
       int c=board[0].size();
       vector<vector<bool>> visited(r,vector<bool>(c,false));
       for(int i=0;i<r;i++)
       for(int j=0;j<c;j++) {
           if( board[i][j]==word[0]) {
               visited[i][j]=true;
               if(word.length()>1)
               dfs(board,visited,i,j,r,c,word,1);
               else 
               return true; 
           }
       }
       return ans;
        
    }
