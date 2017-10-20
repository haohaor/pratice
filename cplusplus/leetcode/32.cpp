class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> sta;
    stack<pair<int, int>> range;
    for (int i = 0; i < s.size(); ++ i) {
      if (s[i] == ')') {
        if (!sta.empty()) {
          auto now = sta.top();
          sta.pop();
          while (!range.empty() && now <= range.top().first && 
              range.top().second <= i) {
            range.pop();
          }
          range.push({now, i});
        }
      } else {
        sta.push(i);
      }
    }
    if (range.empty()) return 0;
    int l = range.top().first, r = range.top().second, ans = r - l + 1;
    range.pop();
    while (!range.empty()) {
      auto now = range.top();
      range.pop();
      if (l - 1 == now.second) {
        l = now.first;
      } else {
        l = now.first;
        r = now.second;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};