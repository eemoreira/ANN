#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

// x[n] = x[n-1] - f[x[n-1]] * ((x[n-1] - x[n-2])/(f[x[n-1]] - f[x[n-2]]))
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto f = [&](long double x) {
        return log(x * x + 2) * exp(acos(-1) - x) - 3;
    };
    long double a, b;
    cin >> a >> b;
    cout << setprecision(15) << fixed;
    const long double delta = 3.61034e-7;
    int cnt = 1;
    long double now = 1e9;
    while (abs(f(now)) >= delta) {
        now = b - f(b) * ((b - a) / (f(b) - f(a)));
        cout << cnt++ << ' ' << now << '\n';
        a = b;
        b = now;
    }
}





