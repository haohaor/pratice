class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> vis(nums.size(), false);
    vector<vector<int>> result;
    vector<int> tmp;
    generate(result, tmp, vis, nums);
    return result;
  }
  void generate(vector<vector<int>>& result, vector<int>& tmp, vector<bool>& vis,
      vector<int>& nums) {
    if (tmp.size() == nums.size()) {
      result.push_back(tmp);
      return ;
    }
    for (int i = 0; i < nums.size(); ++ i) {
      if (!vis[i]) {
        vis[i] = true;
        tmp.push_back(nums[i]);
        generate(result, tmp, vis, nums);
        tmp.pop_back();
        vis[i] = false;
      }
    }
  }
};