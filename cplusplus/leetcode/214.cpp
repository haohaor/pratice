class Solution {
public:
  string shortestPalindrome(string s) {
    int i = 0;
    for (int j = s.size() - 1; j >= 0; -- j) {
      if (s[i] == s[j])
        ++ i;
    }
    if (i == s.size())
      return s;
    string pre = s.substr(i);
    reverse(pre.begin(), pre.end());
    return pre + shortestPalindrome(s.substr(0, i)) + s.substr(i);
  }
};