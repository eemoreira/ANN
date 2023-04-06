#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

// x[n] = x[n-1] - (f[x[n-1]] / df[x[n-1]])
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto f = [&](long double x) {
        return 2664644 - 1021673 * exp(x) - (exp(x) - 1) * 409818.0 / x;
    };
    auto df = [&](long double x) {
        return 1021673 * exp(x) - (exp(x) / (x * x)) * (409818*x - 409818);
    };
    long double a;
    cin >> a;
    cout << setprecision(15) << fixed;
    const long double delta = 3.61034e-7;
    int cnt = 0;
    long double ans = a;
    while (cnt < 20) {
        cnt += 1;
        if (df(ans) == 0.0) {
            cout << "deu merda\n";
            return 0;
        }
        cout << "cnt: " << cnt << ' ' << f(ans) << ' ' << ans << '\n';
        ans -= f(ans) / df(ans);
    }
    cout << cnt << ' ' << ans << ' ' << f(ans) << '\n';
}





