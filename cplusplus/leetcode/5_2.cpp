class Solution {
public:
  string longestPalindrome(string s) {
    int maxL = 1, l = 0, r = 0;
    for (int i = 0; i < s.size(); ++ i) {
      int nowl = i, nowr = i;
      while (nowr + 1 < s.size() && s[i] == s[nowr+1])
        nowr ++;
      i = nowr;
      while (nowl - 1 >= 0 && nowr + 1 < s.size() && s[nowl - 1] == s[nowr + 1]) {
        nowl --;
        nowr ++;
      }
      if (nowr - nowl + 1 > maxL) {
        maxL = nowr - nowl + 1;
        l = nowl;
        r = nowr;
      }
    }
    // string ans = "";
    // for (auto i = l; i <= r; ++ i)
    //   ans += s[i];
    return s.substr(l, maxL);
  }
};