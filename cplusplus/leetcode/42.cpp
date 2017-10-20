class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    stack<pair<int, int>> que;
    int ans = 0;
    que.push({height[0], 0});
    for (auto i = 1; i < height.size(); ++ i) {
      if (que.size() >= 2 && que.top().first <= height[i]) {
        auto nowHeight = que.top().first;
        que.pop();
        while (!que.empty() && que.top().first <= height[i]) {
          ans += (que.top().first - nowHeight) * (i - que.top().second - 1);
          nowHeight = que.top().first;
          que.pop();
        }
        if (!que.empty()) {
          ans += (height[i] - nowHeight) * (i - que.top().second - 1);
        }
      } else {
        while (!que.empty() && que.top().first <= height[i]) {
          que.pop();
        }
      }
      que.push({height[i], i});
    }
    return ans;
  }
};