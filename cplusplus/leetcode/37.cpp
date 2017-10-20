class Solution {
public:
  bool flag = false;
  void solveSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> col(9, vector<bool>(10, false)),
        row(9, vector<bool>(10, false)),
        sub(9, vector<bool>(10, false));
    vector<pair<int, int>> eList;
    flag = false;
    for (int i = 0; i < 9; ++ i) {
      for (int j = 0; j < 9; ++ j) {
        if (board[i][j] != '.') {
          row[i][board[i][j] - '0'] = true;
        } // end if
        if (board[j][i] != '.') {
          col[i][board[j][i] - '0'] = true;
        } // end if
        if (board[i/3*3 + j/3][i%3*3 + j%3] != '.') {
          sub[i][board[i/3*3 + j/3][i%3*3 + j%3] - '0'] = true;
        } // end if
        if (board[i][j] == '.') eList.push_back({i, j});
      } // end for
    } // end for
    find(eList, 0, col, row, sub, board);
  }
  void find(vector<pair<int, int>> &eList, int pos, vector<vector<bool>> &col,
      vector<vector<bool>> &row, vector<vector<bool>> &sub, 
      vector<vector<char>> &board) {
    if (pos == eList.size()) {
      flag = true;
      return;
    } // end if
    auto now = eList[pos];
    int x = now.first, y = now.second, sx = x/3*3 + y/3;
    for (int i = 1; i <= 9; ++ i) {
      if (flag) return;
      if (!row[x][i] && !col[y][i] && !sub[sx][i]) {
        row[x][i] = true;
        col[y][i] = true;
        sub[sx][i] = true;
        board[x][y] = i + '0';
        find(eList, pos + 1, col, row, sub, board);
        if (flag) return;
        row[x][i] = false;
        col[y][i] = false;
        sub[sx][i] = false;
      } // end if
    } // end for
  }
};