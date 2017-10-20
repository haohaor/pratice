class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    map<int, int> cnt;
    sort(candidates.begin(), candidates.end());
    find(ans, tmp, candidates, 0, 0, target);
    return ans;
  }
  void find(vector<vector<int>> &ans, vector<int> &tmp, 
      vector<int> &candidates, int pos, int sum, int target) {
    if (sum == target) {
      ans.push_back(tmp);
      return ;
    }
    for (int i = pos; i < candidates.size(); ++ i) {
      if (i > pos && candidates[i] == candidates[i-1]) continue;
      if (candidates[i] + sum <= target) {
        tmp.push_back(candidates[i]);
        find(ans, tmp, candidates, i + 1, sum + candidates[i], target);
        tmp.pop_back();
      } else if (candidates[i] + sum > target) {
        return ;
      }
    }
  }
};