class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;
    int right = nums.size() - 1;
    while (right > 0 && nums[right] == nums[right - 1])
      -- right;
    if (right == 0) return;
    if (nums[right] > nums[right - 1]) {
      swap(nums[right], nums[right - 1]);
      return;
    }
    while (right > 0 && nums[right - 1] >= nums[right])
      -- right;
    if (right == 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int maxP = right, maxV = nums[right];
    for (auto i = right; i < nums.size(); ++ i) {
      if (nums[i] > nums[right - 1] && nums[i] < maxV) {
        maxV = nums[i];
        maxP = i;
      }
    }
    swap(nums[right - 1], nums[maxP]);
    sort(nums.begin() + right, nums.end());
  }
};