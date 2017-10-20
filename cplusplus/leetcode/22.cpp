class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<pair<string, pair<int, int>>> ans;
    ans.push_back({"", {0, 0}});
    int len = 0;
    while (len < n * 2) {
      vector<pair<string, pair<int, int>>> tmp;
      for (int i = 0; i < ans.size(); ++ i) {
        if (ans[i].second.first > 0) tmp.push_back({ans[i].first + ')', 
            {ans[i].second.first - 1, ans[i].second.second}});
        if (ans[i].second.second + 1 <= n) tmp.push_back({ans[i].first + '(', 
            {ans[i].second.first + 1, ans[i].second.second + 1}});
      }
      len ++;
      ans.swap(tmp);
    }
    vector<string> res;
    for (auto i = 0; i < ans.size(); ++ i)
      res.push_back(ans[i].first);
    return res;
  }
};