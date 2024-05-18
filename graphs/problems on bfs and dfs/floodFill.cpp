class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans,
             vector<vector<int>> &image, int newColor, int delrow[],
             int delcol[], int initialColor)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        // check for neighbor in 4 directions
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && // should be valid
                image[nrow][ncol] == initialColor &&              // if its of inital color and has not been colored yet,color it
                ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, newColor, delrow, delcol,
                    initialColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, color, delrow, delcol, initialColor);
        return ans;
    }
};