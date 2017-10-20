class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int biggerThan10 = 1;
    vector<int> ans;
    for (int i = digits.size() - 1; i >= 0; -- i) {
      ans.push_back((digits[i] + biggerThan10) % 10);
      biggerThan10 = (digits[i] + biggerThan10) / 10;
    }
    if (biggerThan10) {
      ans.push_back(1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};