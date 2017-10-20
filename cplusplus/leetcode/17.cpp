class Solution {
public:
  const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    generate(digits, 0, "", ans);
    return ans;
  }
  void generate(string& digits, int now, string nowS, vector<string>& ans) {
    if (now == digits.size()) {
      if (nowS.size() > 0) ans.push_back(nowS);
      return ;
    }
    int thisChar = digits[now] - '0';
    for (int i = 0; i < v[thisChar].size(); ++ i) {
      generate(digits, now + 1, nowS + v[thisChar][i], ans);
    }
    if (v[thisChar].size() == 0) generate(digits, now + 1, nowS, ans);
  }
};