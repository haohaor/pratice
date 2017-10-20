class Solution {
public:
  void sortColors(vector<int>& nums) {
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < nums.size(); ++ i) {
      cnt[nums[i]] ++;
    }
    int now = 0;
    for (int i = 0; i < 3; ++ i) {
      while (cnt[i]) {
        nums[now ++] = i;
        cnt[i] --;
      }
    }
  }
};