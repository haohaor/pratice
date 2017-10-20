class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    vector<bool> is(nums.size() + 1, false);
    for (auto i = 0; i < nums.size(); ++ i) {
      if (nums[i] >= 0) is[nums[i]] = true;
    }
    for (auto i = 1; i <= nums.size(); ++ i) {
      if (!is[i]) return i;
    }
    return nums.size() + 1;
  }
};