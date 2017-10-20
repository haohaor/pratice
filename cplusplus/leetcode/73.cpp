class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int row = matrix.size(),
        col = matrix[0].size(),
        left = 0,
        right = row * col;
    while (left < right) {
      int mid = (left + right) >> 1,
          nowRow = mid / col,
          nowCol = mid % col;
      if (matrix[nowRow][nowCol] == target) return true;
      else if (matrix[nowRow][nowCol] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return false;
  }
};