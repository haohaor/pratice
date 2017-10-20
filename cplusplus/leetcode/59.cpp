class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int r0 = 0, r1 = n - 1, c0 = 0, c1 = n - 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int num = 1;
    while (r0 <= r1 && c0 <= c1) {
      for (auto i = c0; i <= c1; ++ i) ans[r0][i] = num ++;
      for (auto i = r0 + 1; i <= r1; ++ i) ans[i][c1] = num ++;
      if (r0 < r1 && c0 < c1) {
        for (int i = c1 - 1; i >= c0; -- i) ans[r1][i] = num ++;
        for (int i = r1 - 1; i >= r0 + 1; -- i) ans[i][c0] = num ++;
      }
      ++ r0;
      ++ c0;
      -- r1;
      -- c1;
    }
    return ans;
  }
};