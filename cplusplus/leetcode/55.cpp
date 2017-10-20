class Solution {
public:
  bool canJump(vector<int>& nums) {
    int next = 0, pre = 0, now = 0;
    while (next < nums.size() - 1) {
      while (now <= pre) {
        next = max(next, now + nums[now]);
        if (next >= nums.size() - 1) break;
        ++ now;
      }
      if (pre == next) break;
      pre = next;
    }
    return next >= nums.size() - 1;
  }
};