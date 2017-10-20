class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[l] == target) return l;
      if (nums[r] == target) return r;
      if (nums[m] == target) return m;
      else {
        if (nums[l] > target && nums[r] < target) return -1;
        else if ((nums[l] <= target && nums[l] > nums[m]) || 
          (nums[l] < target && target < nums[m]) ||
          (nums[m] > target && nums[m] < nums[l])) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } // end if
    } // end while
    return -1;
  }
};