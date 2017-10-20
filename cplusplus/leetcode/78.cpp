class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    ans.push_back({});
    generate(ans, tmp, 0, nums);
    return ans;
  }
  void generate(vector<vector<int>>& ans, vector<int>& tmp, int now, 
      vector<int>& nums) {
    if (tmp.size() == nums.size()) {
      return;
    }
    for (auto i = now; i < nums.size(); ++ i) {
      tmp.emplace_back(nums[i]);
      ans.emplace_back(tmp);
      generate(ans, tmp, i + 1, nums);
      tmp.pop_back();
    }
  }
};