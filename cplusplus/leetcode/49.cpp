class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<pair<string, string>> strs2;
    for (auto str: strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      strs2.push_back({tmp, str});
    }
    sort(strs2.begin(), strs2.end(), [](pair<string, string>& a, pair<string, string>& b) {
      return a.first < b.first;
    });
    vector<vector<string>> ans;
    vector<string> pre;
    for (int i = 0; i < strs2.size(); ++ i) {
      if (i == 0) {
        pre.push_back(strs2[i].second);
      } else if (strs2[i].first == strs2[i-1].first) {
        pre.push_back(strs2[i].second);
      } else {
        ans.push_back(pre);
        pre.clear();
        pre.push_back(strs2[i].second);
      }
    }
    if (!pre.empty()) ans.push_back(pre);
    return ans;
  }
};