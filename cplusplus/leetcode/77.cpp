class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;
    generate(ans, tmp, 1, n, k);
    return ans;
  }
  void generate(vector<vector<int>> &ans, vector<int>& tmp, int now, int n, int k) {
    if (tmp.size() == k) {
      ans.emplace_back(tmp);
      return ;
    }
    for (int i = now; i <= n; ++ i) {
      tmp.emplace_back(i);
      generate(ans, tmp, i + 1, n, k);
      tmp.pop_back();
    }
  }
};