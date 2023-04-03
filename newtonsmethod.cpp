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
        return log(x * x + 2) * exp(acos(-1) - x) - 3;
    };
    auto df = [&](long double x) {
        return 2 * x * exp(acos(-1) - x) / (x * x + 2) - exp(acos(-1) - x) * log(x * x + 2);
    };
    long double a;
    cin >> a;
    cout << setprecision(15) << fixed;
    const long double delta = 3.61034e-7;
    int cnt = 0;
    long double ans = a;
    while (abs(f(ans)) >= delta) {
        cnt += 1;
        if (df(ans) == 0.0) {
            cout << "deu merda\n";
            return 0;
        }
        dbg(f(ans),ans,cnt);
        ans -= f(ans) / df(ans);
    }
    cout << cnt << ' ' << ans << ' ' << f(ans) << '\n';
}





