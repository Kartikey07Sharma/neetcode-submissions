class Solution {
public:

    void BFS(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i, j});
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        while(!q.empty())
        {
            auto x = q.front();
            int row = x.first;
            int col = x.second;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0 ;j<m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    BFS(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
