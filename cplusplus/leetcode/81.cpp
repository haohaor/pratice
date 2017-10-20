class Solution {
public:
  bool search(vector<int>& nums, int target) {
    if (nums.empty()) return false;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (l + r) >> 1;
      if (nums[m] == target) return true;
      if (nums[m] < target) {
        if (nums[l] <= target && nums[l] > nums[m]) r = m;
        else l = m + 1;
      } else {
        if ((target < nums[l] && nums[l] < nums[m]) || (l == m)) 
          l = m + 1;
        else r = m;
      }
    }
    if (nums[l] == target) return true;
    return false;
  }
};