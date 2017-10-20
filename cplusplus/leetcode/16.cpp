class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = 0, minD = (1LL << 31) - 1;
    for (auto i = 0; i < nums.size(); ++ i) {
      int k = nums.size() - 1;
      for (auto j = i + 1; j < nums.size(); ++ j) {
        int tar = target - nums[i] - nums[j];
        while (k > j && nums[k] > tar) {
          update(minD, ans, tar - nums[k], nums[i] + nums[j] + nums[k]);
          k --;
        }
        if (k > j) update(minD, ans, tar - nums[k], nums[i] + nums[j] + nums[k]);
        if (k + 1 < nums.size()) update(minD, ans, tar - nums[k + 1], nums[i] + nums[j] + nums[k + 1]);
        if (k - 1 > j) update(minD, ans, tar - nums[k - 1], nums[i] + nums[j] + nums[k - 1]);
      }
    }
    return ans;
  }
  void update(int& minD, int& ans, int d, int threeSum) {
    if (abs(d) < minD) {
      minD = abs(d);
      ans = threeSum;
    }
  }
};