// using bfs
class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            for (auto dir : directions)
            {
                int newRow = curRow + dir.first;
                int newCol = curCol + dir.second;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1' && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
        // alternative
        // while (!q.empty())
        // {
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     q.pop();
        //     for (int delrow = -1; delrow <= 1; delrow++)
        //     {
        //         for (int delcol = -1; delcol <= 1; delcol++)
        //         {
        //             int nrow = row + delrow;
        //             int ncol = col + delcol;
        //             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
        //             {
        //                 visited[nrow][ncol] = 1;
        //                 q.push({nrow, ncol});
        //             }
        //         }
        //     }
        // }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    bfs(row, col, visited, grid);
                    count++;
                }
            }
        }

        return count;
    }
};

// using dfs
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1')
                {
                    count++;
                    dfs(grid, row, col);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
        {
            return;
        }
        grid[row][col] = '0';
        dfs(grid, row - 1, col); //  move up
        dfs(grid, row + 1, col); // down
        dfs(grid, row, col - 1); // left
        dfs(grid, row, col + 1); // right
    }
};