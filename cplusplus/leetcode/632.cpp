class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    if (nums.size() == 1) return {nums[0][0], nums[0][0]};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> minQue;
    int l = -100000, r = 100000, maxV = -100000;
    for (auto i = 0; i < nums.size(); ++ i) {
      minQue.push({nums[i][0], {i, 0}});
      maxV = max(maxV, nums[i][0]);
    } // end for
    vector<int> pos(nums.size(), 0);
    while (minQue.size() >= nums.size()) {
      auto minNow = minQue.top();
      auto minPos = minNow.second;
      minQue.pop();
      if (r - l > maxV - minNow.first) {
        l = minNow.first;
        r = maxV;
      }
      if (minPos.second + 1 < nums[minPos.first].size()) {
        minQue.push({nums[minPos.first][minPos.second + 1],
            {minPos.first, minPos.second + 1}});
        maxV = max(maxV, nums[minPos.first][minPos.second + 1]);
        pos[minPos.first] = minPos.second + 1;
      } // end if
    } // end while
    return {l ,r};
  }
};