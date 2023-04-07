#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

// busca binaria padrao
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto f = [&](long double x) {
      return 3040754 - 1241839 * exp(x) - (exp(x) - 1) * 408181.0 / x;
  };
  long double a,b;
  cin >> a >> b;
  dbg(a,b);
  if (f(a) * f(b) >= 0) {
    cout << "merda\n";
    return 0;
  }
  const long double delta = 3.61034e-7;
  int cnt = 0;
  cout << setprecision(15) << fixed;
  bool w = f(a) > f(b);
  function<long double(long double,long double)> bs = [&](long double l, long double r) {
    long double mid = (l + r) / 2.0;
    cout << "iter: " << (++cnt) << ' ';
    cout << mid << ' ' << f(mid) << '\n';
    if (abs(f(mid)) < delta) return f(mid);
    if (f(mid) < 0) { 
      return w ? bs(l, mid) : bs(mid, r);
    }
    return w ? bs(mid, r) : bs(l, mid);
  };
  cout << bs(a,b) << '\n';
}





