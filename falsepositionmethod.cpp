#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto f = [&](long double x) {
        ld n = 130869380;
        ld t = n / 4;
        ld d = 1.41e-10;
        ld y = 1 + n * exp(-d * (n + 1) * x);
        return t - (n + 1) / y;
    };
    long double a,b;
    cin >> a >> b;
    if (f(a) * f(b) > 0) {
        cout << "deu merda\n";
        return 0;
    }
    cout << setprecision(15) << fixed;
    for (int i = 0; i < 20; i++) {
        double c = b - f(b) * ((b - a) / (f(b) - f(a)));
        if (f(c) * f(b) > 0) {
            // if c and b have same sign
            b = c;
        }
        else {
            // if c and a have samen sign
            a = c;
        }
        cout << "iter: " << i+1 << ' ' << c << ' ' << f(c) << '\n';
    }
    /* const long double delta = 3.61034e-7; */
    /* int cnt = 0; */
    /* double ans = 0; */
    /* while (abs(f(ans)) >= delta) { */
    /*     ans = b - f(b) * ((b - a) / (f(b) - f(a))); */
    /*     if (f(ans) * f(b) > 0) { */
    /*         b = ans; */
    /*     } */
    /*     else { */
    /*         a = ans; */
    /*     } */
    /*     cout << ++cnt << ' ' << ans << ' ' << f(ans) << '\n'; */
    /* } */
}
