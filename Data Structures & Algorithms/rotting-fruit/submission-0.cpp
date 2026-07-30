class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        vector<vector<int>> vis(n ,vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)fresh++;
            }
        }

        if(fresh == 0)return 0;
        int time = 0;
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1}; 
        while(!q.empty())
        {
            int size = q.size();
            bool rotten = false;
            for(int i = 0; i<size; i++)
            {
                auto x = q.front();
                int row = x.first;
                int col = x.second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int nrow = row + drow[k];
                    int ncol = col + dcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                    {
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten)
            {
                time++;
            }
        } 
        if(fresh > 0)return -1;
        return time;   
    }
};
