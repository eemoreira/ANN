#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

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
        ld a = 15.44;
        ld b = 9.59;
        return 12 * x * x - x * (4 * b + 4 * a) + a * b;
    };
    long double a, b;
    cin >> a >> b;
    cout << setprecision(15) << fixed;
    const long double delta = 3.61034e-10;
    int cnt = 1;
    long double now = 1e9;
    while (cnt < 20) {
        now = b - f(b) * ((b - a) / (f(b) - f(a)));
        cout << cnt++ << ' ' << now << '\n';
        a = b;
        b = now;
    }
}





