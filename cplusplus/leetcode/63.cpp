class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) return 0;
    int ans = 0;
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    if (obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;
    for (int i = 0; i < row; ++ i) {
      for (int j = 0; j < col; ++ j) {
        if (i == 0 && j == 0) continue;
        if (obstacleGrid[i][j] == 0) {
          if (i == 0) dp[i][j] = dp[i][j-1];
          else if (j == 0) dp[i][j] = dp[i-1][j];
          else {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
          }
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return dp[row - 1][col - 1];
  }
};