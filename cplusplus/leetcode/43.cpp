class Solution {
public:
  string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ans = "";
    for (int i = 0; i < num1.size(); ++ i) {
      string tmp = "";
      int jin = 0;
      for (int j = 0; j < num2.size(); ++ j) {
        tmp += multi(num1[i], num2[j], jin);
      }
      if (jin) tmp += jin + '0';
      jin = 0;
      for (int j = 0; j < tmp.size(); ++ j) {
        char now = add(tmp[j], i + j < ans.size() ? ans[i+j]: '0', jin);
        if (i + j < ans.size()) ans[i+j] = now;
        else ans += now;
      }
      if (jin) ans += jin + '0';
    }
    while (!ans.empty() && ans.back() == '0')
      ans.pop_back();
    reverse(ans.begin(), ans.end());
    if (ans.empty()) return "0";
    return ans;
  }
  char multi(char a, char b, int &jin) {
    int nowa = a - '0';
    int nowb = b - '0';
    int ans = (nowa * nowb + jin) % 10;
    jin = (nowa * nowb + jin) / 10;
    return ans + '0';
  }
  char add(char a, char b, int &jin) {
    int nowa = a - '0';
    int nowb = b - '0';
    int ans = (nowa + nowb + jin) % 10;
    jin = (nowa + nowb + jin) / 10;
    return ans + '0';
  }
};