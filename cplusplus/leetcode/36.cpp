class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++ i) {
      map<char, bool> row, col, sub;
      for (int j = 0; j < 9; ++ j) {
        char now;
        if (board[i][j] != '.') {
          now = board[i][j];
          if (!row[now]) {
            row[now] = true;
          } else return false;
        }
        if (board[j][i] != '.') {
          now = board[j][i];
          if (!col[now]) {
            col[now] = true;
          } else return false;
        }
        if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.') {
          now = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
          if (!sub[now]) {
            sub[now] = true;
          } else return false;
        }
      }
    }
    return true;
  }
};