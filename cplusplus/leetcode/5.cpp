class Solution {
public:
  string longestPalindrome(string s) {
    int dp[1000][1000];
    memset(dp, 0, sizeof(dp));
    for (auto i = 0; i < s.size(); ++ i)
      dp[i][i] = 1;
    int ansV = 1, l = 0, r = 0;
    for (int j = 1; j <= s.size(); ++ j) {
      for (int i = 0; i < s.size(); ++ i) {
        if (i + j - 1 >= s.size()) break;
        // cout << i << "  " << i + j - 1 << " **** " << endl;
        int k = i + j - 1;
        if (i > 0 && k + 1 < s.size() && s[i-1] == s[k+1] && dp[i][k] == k - i + 1) {
          dp[i-1][k+1] = max(dp[i-1][k+1], dp[i][k] + 2);
          // cout << i-1 << "  " << k+1 << " " << dp[i-1][k+1] << " ___ " << endl;
          if (ansV < dp[i-1][k+1]) {
            ansV = dp[i-1][k+1];
            l = i - 1;
            r = k + 1;
          }
        }
        if (j == 1 && k + 1 < s.size() && s[i] == s[k + 1] && dp[i][k] == k - i + 1) {
          dp[i][k + 1] = max(dp[i][k + 1], dp[i][k] + 1);
          // cout << i << "  " << k + 1 << "  " << dp[i][k + 1] << endl;
          if (ansV < dp[i][k + 1]) {
            ansV = dp[i][k + 1];
            l = i;
            r = k + 1;
          }
        }
      }
    }
    string ans = "";
    for (auto i = l; i <= r; ++ i)
      ans += s[i];
    return ans;
  }
};