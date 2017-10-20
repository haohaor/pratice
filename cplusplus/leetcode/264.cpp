class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    dp[0] = 1;
    int val[3] = {2, 3, 5},
        index[3] = {0, 0, 0},
        init[3] = {2, 3, 5};
    for (auto i = 1; i < n; ++ i) {
      auto now = min(val[0], min(val[1], val[2]));
      for (auto j = 0; j < 3; ++ j) {
        if (now == val[j]) {
          dp[i] = now;
          ++ index[j];
          val[j] = dp[index[j]] * init[j];
        }
      }
    }
    return dp[n - 1];
  }
};