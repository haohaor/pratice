class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty()) return 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    const auto row = heightMap.size(), col = heightMap[0].size();
    vector<vector<bool>> vis(row, vector<bool> (col, false));
    for (auto i = 0; i < row; ++ i) {
      for (auto j = 0; j < col; ++ j) {
        if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
          que.push({heightMap[i][j], i * col + j});
          vis[i][j] = true;
        }
      }
    }
    vector<vector<int>> d{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int maxHeight = 0,
        ans = 0;
    while (!que.empty()) {
      auto now = que.top();
      que.pop();
      auto x = now.second / col, y = now.second % col;
      maxHeight = max(maxHeight, now.first);
      for (int i = 0; i < 4; ++ i) {
        auto nx = x + d[i][0], ny = y + d[i][1];
        if (nx < 0 || nx >= row || ny < 0 || ny >= col || vis[nx][ny]) continue;
        if (heightMap[nx][ny] < maxHeight) ans += maxHeight - heightMap[nx][ny];
        vis[nx][ny] = true;
        que.push({heightMap[nx][ny], nx * col + ny});
      }
    }
    return ans;
  }
};