class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int L = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int R = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    -- R;
    if (L == nums.size()) {
      return {-1, -1};
    } else if (L > R) {
      return {-1, -1};
    }
    return {L, R};
  }
};