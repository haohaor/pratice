class Solution {
public:
  int jump(vector<int>& nums) {
    int ans = 0, maxdis = 0, predis = 0, start = 0;
    while (start < nums.size() && maxdis <= int(nums.size()) - 2) {
      ++ ans;
      while (start <= predis) {
        maxdis = max(maxdis, nums[start] + start);
        if (maxdis >= nums.size() - 1) return ans;
        ++ start;
      } // end while
      predis = maxdis;
    } // end while
    return ans;
  }
};