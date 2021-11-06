

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL n;

LL gao(LL x) {
  LL ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &n);
    LL a = 0;
    while (a <= n) {
      a = a * 10 + 9;
    }
    a /= 10;
    printf("%lld\n", gao(a) + gao(n - a));
  }
  return 0;
}












