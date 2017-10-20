class Solution {
public:
  int maxArea(vector<int>& height) {
    vector<pair<int, int>> hei;
    for (int i = 0; i < height.size(); ++ i) {
      hei.push_back({i, height[i]});
    }
    sort(hei.begin(), hei.end(), [](pair<int, int> &a, pair<int, int> &b) {
      if (a.second != b.second) {
        return a.second < b.second;
      }
      return a.first < b.first;
    });
    vector<pair<int, int>> maxMinLen(height.size(), {0, 0});
    maxMinLen[height.size() - 1] = {hei[hei.size() - 1].first, 
        hei[hei.size() - 1].first};
    for (int i = hei.size() - 2; i >= 0; -- i) {
      maxMinLen[i].first = max(hei[i].first, maxMinLen[i + 1].first);
      maxMinLen[i].second = min(hei[i].first, maxMinLen[i + 1].second);
    }
    int ans = 0;
    for (int i = 0; i < hei.size() - 1; ++ i) {
      ans = max(ans, hei[i].second * abs(maxMinLen[i + 1].first - hei[i].first));
      ans = max(ans, hei[i].second * abs(maxMinLen[i + 1].second - hei[i].first));
    }
    return ans;
  }
};