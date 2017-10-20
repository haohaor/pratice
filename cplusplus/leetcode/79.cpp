class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  }
  bool find(vector<vector<char>>& board, string& word,int x, int y,
      int now, vector<vector<int>>& dir) {
    for (int i = 0; i < 4; ++ i) {
      int nx = x + dir[i][0],
          ny = y + dir[i][1];

    }
  }
};