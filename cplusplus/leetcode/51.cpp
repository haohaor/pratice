class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<bool> col(n, false),
        dia(2 * n, false),
        ndia(2 * n, false);
    vector<vector<string>> ans;
    vector<string> tmp(n, string(n, '.'));
    getSolution(ans, tmp, 0, col, dia, ndia);
    return ans;
  }
  void getSolution(vector<vector<string>>& ans, vector<string>& tmp, int row,
      vector<bool>& col, vector<bool>& dia, vector<bool>& ndia) {
    if (row == tmp.size()) {
      ans.push_back(tmp);
      return ;
    }
    for (int i = 0; i < tmp.size(); ++ i) {
      if (!col[i] && !dia[row - i + tmp.size()] && !ndia[row + i]) {
        col[i] = true;
        dia[row - i + tmp.size()] = true;
        ndia[row + i] = true;
        tmp[row][i] = 'Q';
        getSolution(ans, tmp, row + 1, col, dia, ndia);
        col[i] = false;
        dia[row - i + tmp.size()] = false;
        ndia[row + i] = false;
        tmp[row][i] = '.';
      } // end if
    } // end for
  }
};