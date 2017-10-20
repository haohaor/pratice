class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    map<int, int> cnt;
    for (auto num: nums) ++ cnt[num];
    vector<vector<int>> result;
    vector<int> tmp;
    generate(cnt, result, tmp, nums.size());
    return result;
  }
  void generate(map<int, int> &cnt, vector<vector<int>>& result, 
      vector<int> tmp, int total) {
    if (tmp.size() == total) {
      result.push_back(tmp);
      return ;
    } // end if
    for (auto it = cnt.begin(); it != cnt.end(); ++ it) {
      if (it -> second > 0) {
        tmp.push_back(it -> first);
        -- it -> second;
        generate(cnt, result, tmp, total);
        tmp.pop_back();
        ++ it -> second;
      } // end if
    } // end for
  }
};