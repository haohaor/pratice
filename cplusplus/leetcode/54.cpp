class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    int sx = 0, sy = 0, dirP = 0;
    vis[sx][sy] = true;
    ans.push_back(matrix[sx][sy]);
    if (ans.size() == row * col) return ans;
    while (true) {
      int nx = sx + dir[dirP][0], ny = sy + dir[dirP][1];
      while (!check(nx, ny, row, col, vis)) {
        dirP = (dirP + 1) % 4;
        nx = sx + dir[dirP][0];
        ny = sy + dir[dirP][1];
      }
      vis[nx][ny] = true;
      ans.push_back(matrix[nx][ny]);
      if (ans.size() == row * col) break;
      sx = nx;
      sy = ny;
    }
    return ans;
  }
  bool check(int x, int y, int row, int col, vector<vector<bool>>& vis) {
    if (x >= 0 && x < row && y >= 0 && y < col && !vis[x][y]) {
      return true;
    }
    return false;
  }
};