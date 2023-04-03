#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto f = [&](double x) {
        return log(x * x + 2) * exp(acos(-1) - x) - 3;
    };
    double a,b;
    cin >> a >> b;
    if (f(a) * f(b) > 0) {
        cout << "deu merda\n";
        return 0;
    }
    cout << setprecision(15) << fixed;
    /* for (int i = 0; i < 20; i++) { */
    /*     cout << i + 1 << ' '; */
    /*     double c = b - f(b) * ((b - a) / (f(b) - f(a))); */
    /*     if (f(c) * f(b) > 0) { */
    /*         // if c and b have same sign */
    /*         b = c; */
    /*     } */
    /*     else { */
    /*         // if c and a have samen sign */
    /*         a = c; */
    /*     } */
    /*     cout << c << ' ' << f(c) << '\n'; */
    /* } */
    const long double delta = 3.61034e-7;
    int cnt = 0;
    double ans = 0;
    while (abs(f(ans)) >= delta) {
        ans = b - f(b) * ((b - a) / (f(b) - f(a)));
        if (f(ans) * f(b) > 0) {
            b = ans;
        }
        else {
            a = ans;
        }
        cout << ++cnt << ' ' << ans << ' ' << f(ans) << '\n';
    }
}
