#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int t;
int x[3], y[3], z[3];

int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  cin >> t;
  for (int Case = 1; Case <= t; ++ Case) {
    for (int i = 0; i < 3; ++ i) {
      cin >> x[i] >> y[i] >> z[i];
    }
    int minx = x[0], maxx = x[0];
    for (int i = 1; i < 3; ++ i) {
      minx = min(minx, x[i]);
      maxx = max(maxx, x[i]);
    }
    cout << "Case #" << Case << ": ";
    printf("%.6lf\n", (maxx - minx) / 6.0);
  }
  return 0;
}