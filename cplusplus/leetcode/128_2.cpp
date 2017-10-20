#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int val : nums) {
      if (cnt.count(val)) continue;
      if (cnt.count(val-1) && cnt.count(val+1)) {
        int left = cnt[val-1];
        int right = cnt[val+1];
        cnt[val-left] += right + 1;
        cnt[val+right] += left + 1;
        cnt[val] = 1;
        // cout << cnt[val-left] << " " << cnt[val] << " " << cnt[val+right] << endl;
      } else if (cnt.count(val-1) && !cnt.count(val+1)) {
        int left = cnt[val-1];
        cnt[val-left] ++;
        cnt[val] = left + 1;
        // cout << cnt[val-left] << " " << cnt[val] << " " << endl;
      } else if (!cnt.count(val-1) && cnt.count(val+1)) {
        int right = cnt[val+1];
        cnt[val+right] ++;
        cnt[val] = right + 1;
        // cout << cnt[val] << " " << cnt[val+right] << endl;
      } else {
        cnt[val] = 1;
      }
    }
    int ans = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++ it) {
      ans = max(ans, it -> second);
    }
    return ans;
  }
};

int main() {
  vector<int> nums{4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
  Solution a;
  cout << a.longestConsecutive(nums) << endl;
  return 0;
}