class Solution {
  public:
  string getPermutation(int n, int k) {
    string ans = "";
    vector<int> p(n + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= n; ++ i) 
      p[i] = p[i-1] * i;
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n; ++ i) {
      int pre = 0;
      for (int j = 1; j <= n; ++ j) {
        if (vis[j]) continue;
        if (pre * p[n - i - 1] < k && k <= (pre + 1) * p[n - i - 1]) {
          ans += j + '0';
          k -= pre * p[n - i - 1];
          vis[j] = true;
          break;
        } else {
          ++ pre;
        }
      }
    }
    return ans;
  }
};