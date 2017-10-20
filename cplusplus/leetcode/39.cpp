class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
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
      if (candidates[i] + sum <= target) {
        tmp.push_back(candidates[i]);
        find(ans, tmp, candidates, i, sum + candidates[i], target);
        tmp.pop_back();
      } else {
        return ;
      }
    }
  }
};