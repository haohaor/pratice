class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    return findkth(nums, 0, nums.size() - 1, k);
  }
  int findkth(vector<int>& nums, int l, int r, int k) {
    int nowl = l, nowr = r, key = nums[l];
    cout << l << "  " << r << "  " << k << endl;
    while (nowl < nowr) {
      while (nowl < nowr && nums[nowr] >= key) nowr --;
      nums[nowl] = nums[nowr];
      while (nowl < nowr && nums[nowl] <= key) nowl ++;
      nums[nowr] = nums[nowl];
    }
    nums[nowl] = key;
    if (r - nowl + 1 == k) return key;
    else if (k < r - nowl + 1) return findkth(nums, nowl + 1, r, k);
    else return findkth(nums, l, nowl - 1, k - (r - nowl + 1));
  }
};