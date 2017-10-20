class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    map<int, int> cnt;
    sort(candidates.begin(), candidates.end());
    vector<int> unique;
    for (int i = 0; i < candidates.size(); ++ i) {
      if (i == 0) {
        unique.push_back(candidates[i]);
      } else {
        if (candidates[i] != candidates[i-1]) {
          unique.push_back(candidates[i]);
        }
      }
      ++ cnt[candidates[i]];
    }
    find(ans, tmp, unique, 0, 0, target, cnt);
    return ans;
  }
  void find(vector<vector<int>> &ans, vector<int> &tmp, 
      vector<int> &candidates, int pos, int sum, int target, map<int, int> &cnt) {
    if (sum == target) {
      ans.push_back(tmp);
      return ;
    }
    for (int i = pos; i < candidates.size(); ++ i) {
      if (cnt[candidates[i]] > 0 && candidates[i] + sum <= target) {
        tmp.push_back(candidates[i]);
        cnt[candidates[i]] --;
        find(ans, tmp, candidates, i, sum + candidates[i], target, cnt);
        tmp.pop_back();
        cnt[candidates[i]] ++;
      } else if (candidates[i] + sum > target) {
        return ;
      }
    }
  }
};