class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    vector<int> ans;
    priority_queue<pair<int, int>> que;
    for (auto i = 0; i < k; ++ i) que.push({nums[i], i});
    ans.push_back(que.top().first);
    if (que.top().second == 0) que.pop();
    for (auto i = 1; i + k - 1 < nums.size(); ++ i) {
      que.push({nums[i+k-1], i+k-1});
      while (que.top().second < i || que.top().second > i + k - 1) {
        que.pop();
      }
      ans.push_back(que.top().first);
    }
    return ans;
  }
};