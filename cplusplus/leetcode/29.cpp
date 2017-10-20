class Solution {
public:
  int divide(int dividend, int divisor) {
    const int MAX_INT = (1LL << 31) - 1;
    const int MIN_INT = - (1LL << 31);
    if (divisor == 0) return MAX_INT;
    if (dividend < divisor) return 0;
    bool flag = ((dividend > 0 && divisor < 0) || 
        (dividend < 0 && divisor > 0)) ? true : false;
    long long div0 = abs(dividend * 1LL), div1 = abs(divisor * 1LL);
    long long ans = 0;
    while (div0 >= div1) {
      long long cnt = 0, tmp = div1;
      while (div0 * 1LL > (tmp << cnt)) {
        cnt ++;
      }
      ans += 1LL << (cnt - 1);
      div0 -= tmp << (cnt - 1);
    }
    if (flag) ans *= -1;
    if (ans > MAX_INT || ans < MIN_INT)
      return MAX_INT;
    return ans;
  }
};