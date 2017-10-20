class Solution {
public:
  int totalNQueens(int n) {
    vector<bool> col(n, false),
        dia(2 * n, false),
        ndia(2 * n, false);
    int num = 0;
    getNQueens(n, num, 0, col, dia, ndia);
    return num;
  }
  void getNQueens(int colSum, int &num, int row, vector<bool>& col, vector<bool>& dia, 
        vector<bool>& ndia) {
    if (row == colSum) {
      ++ num;
      return ;
    } // end if
    for (auto i = 0; i < colSum; ++ i) {
      if (!col[i] && !dia[row - i + colSum] && !ndia[row + i]) {
        col[i] = true;
        dia[row - i + colSum] = true;
        ndia[row + i] = true;
        getNQueens(colSum, num, row + 1, col, dia, ndia);
        col[i] = false;
        dia[row - i + colSum] = false;
        ndia[row + i] = false;
      } // end if
    } // end for
  }
};