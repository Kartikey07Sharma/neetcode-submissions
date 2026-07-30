class Solution {
public:

    void dfs(int row, int col, vector<vector<int>> &grid,
             vector<vector<int>> &vis, int &cnt)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++)
        {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];

            if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
            {
                cnt++;
            }
            else if(grid[nrow][ncol] == 0)
            {
                cnt++;
            }
            else if(vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, grid, vis, cnt);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j, grid, vis, cnt);
                    return cnt;  
                }
            }
        }

        return 0;
    }
};