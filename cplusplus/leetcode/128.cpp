class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    priority_queue<int> que;
    for (int i = 0; i < nums.size(); ++ i) {
      que.push(nums[i]);
    }
    int start = que.top(), ans = 1, pre = que.top();
    while (!que.empty()) {
      int now = que.top();
      que.pop();
      if (pre - now <= 1) {
        ans = max(ans, start - now + 1);
      } else {
        start = now;
      }
      pre = now;
    }
    return ans;
  }
};