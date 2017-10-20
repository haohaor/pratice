class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < row; ++ i) {
      for (int j = 0; j < col; ++ j) {
        if (i == 0 && j == 0) continue;
        else if (i == 0) {
          dp[i][j] = dp[i][j-1];
        } else if (j == 0) {
          dp[i][j] = dp[i-1][j];
        } else {
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
        } // end if
        dp[i][j] += grid[i][j];
      } // end for
    } // end for
    return dp[row - 1][col - 1];
  }
};