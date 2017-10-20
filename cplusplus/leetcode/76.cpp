class Solution {
public:
  string minWindow(string s, string t) {
    int minP = -1, minW = -1;
    int SLen = s.size();
    int tLen = t.size();
    vector<int> sum(256, 0);
    int cnt[256];
    memset(cnt, 0, sizeof(cnt));
    for (auto i = 0; i < tLen; ++ i) cnt[t[i]] ++;
    int okSum = 0;
    for (int i = 0, j = 0; i < SLen; ++ i) {
      while (j < SLen && (sum[s[j]] < cnt[s[j]] || okSum < tLen)) {
        if (cnt[s[j]]) sum[s[j]] ++;
        if (cnt[s[j]] && sum[s[j]] <= cnt[s[j]]) okSum ++;
        ++ j;
      }
      while (i < SLen && i <= j && (sum[s[i]] > cnt[s[i]] || !cnt[s[i]])) {
        if (cnt[s[i]]) sum[s[i]] --;
        i ++;
      }
      if (okSum == tLen) {
        if (minW == -1 || minW > j - i) {
          minW = j - i;
          minP = i;
        }
      }
      if (j == SLen) break;
      if (cnt[s[i]] && sum[s[i]] <= cnt[s[i]]) {
        sum[s[i]] --;
        okSum --;
      }
    }
    if (minW == -1) return "";
    return s.substr(minP, minW);
  }
};