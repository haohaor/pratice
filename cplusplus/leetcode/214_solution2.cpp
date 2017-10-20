class Solution {
public:
  string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string s2 = s + '#' + rev;
    vector<int> f(s2.size());
    f[0] = 0;
    for (int i = 1; i < s2.size(); ++ i) {
      int t = f[i - 1];
      while (s2[i] != s2[t] && t > 0)
        t = f[t - 1];
      if (s2[i] == s2[t])
        ++ t;
      f[i] = t;
    }
    return rev.substr(0, rev.size() - f[s2.size() - 1]) + s;
  }
}