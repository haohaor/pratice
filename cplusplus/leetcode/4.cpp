class Solution {
public:
  void pushQueue(priority_queue<int> &large, priority_queue<int, vector<int>, 
      greater<int>> &small, vector<int> &nums) {
    for (auto i = 0; i < nums.size(); ++ i) {
      auto now = nums[i];
      if (large.size() && large.size() > small.size()) {
        if (now < large.top()) {
          small.push(large.top());
          large.pop();
          large.push(now);
        } else {
          small.push(now);
        }
      } else {
        if (small.size() && now > small.top()) {
          large.push(small.top());
          small.pop();
          small.push(now);
        } else {
          large.push(now);
        }
      }
    }
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    priority_queue<int> large;
    priority_queue<int, vector<int>, greater<int>> small;
    pushQueue(large, small, nums1);
    pushQueue(large, small, nums2);
    if (large.size() > small.size()) {
      return large.top();
    } else if (large.size() < small.size()) {
      return small.top();
    } else {
      return (large.top() + small.top()) / 2.0;
    }
  }
};