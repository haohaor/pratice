class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int c0 = 0, c1 = col - 1, r0 = 0, r1 = row - 1;
    while (c0 <= c1 && r0 <= r1) {
      for (int i = c0; i <= c1; ++ i) ans.push_back(matrix[r0][i]);
      for (int i = r0 + 1; i <= r1; ++ i) ans.push_back(matrix[i][c1]);
      if (c0 < c1 && r0 < r1) {
        for (int i = c1 - 1; i >= c0; -- i) ans.push_back(matrix[r1][i]);
        for (int i = r1 - 1; i >= r0 + 1; -- i) ans.push_back(matrix[i][c0]);
      }
      ++ c0;
      ++ r0;
      -- c1;
      -- r1;
    }
    return ans;
  }
};