/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    auto cmp = [](Interval& a, Interval& b) {
      if (a.start != b.start) {
        return a.start < b.start;
      } else {
        return a.end < b.end;
      }
    };
    priority_queue<Interval, vector<Interval>, decltype(cmp)> que(cmp);
    que.push(newInterval);
    for (int i = 0; i < intervals.size(); ++ i) {
      // cout << que.top().start << " " << que.top().end << " " << intervals[i].start << " " << intervals[i].end << endl;
      if (!(que.top().start > intervals[i].end || 
          que.top().end < intervals[i].start)) {
        intervals[i].start = min(que.top().start, intervals[i].start);
        intervals[i].end = max(que.top().end, intervals[i].end);
        que.pop();
      }
      que.push(intervals[i]);
    }
    vector<Interval> ans;
    while (!que.empty()) {
      ans.insert(0, que.top());
      que.pop();
    }
    return ans;
  }
};