class Solution {
public:

    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        int n = board.size();
        int m = board[0].size();
        for(int k=0; k<4; k++)
        {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j=0; j<m; j++)
        {
            if(board[0][j] == 'O' && vis[0][j] == 0)
            {
                dfs(0, j, board, vis);
            }
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0)
            {
                dfs(n-1, j, board, vis);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(board[i][0] == 'O' && vis[i][0] == 0)
            {
                dfs(i, 0, board, vis);
            } 
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0)
            {
                dfs(i, m-1, board, vis);
            }
        }    

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
