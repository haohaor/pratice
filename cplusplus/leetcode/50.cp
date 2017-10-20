class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    double ans = 1;
    bool flag = n < 0 ? true : false;
    n = abs(n);
    while (n) {
      if (n & 1) ans *= x;
      x *= x;
      n >>= 1;
    }
    return flag ? 1 / ans : ans;
  }
};