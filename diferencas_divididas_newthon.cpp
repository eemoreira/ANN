#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */

vector<long double> dif_div(vector<long double> &x, vector<long double> &y) {
    int n = y.size();
    vector<long double> c = {y[0]};
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            long double a = (y[j + 1] - y[j]) / (x[j + i + 1] - x[j]);
            y[j] = a;
        }
        c.emplace_back(y[0]);
    }
    return c;
}

long double poly(long double t, vector<long double>&x, vector<long double>&coef) {
    int n = x.size();
    long double ans = coef[0];
    for (int i = 0; i < n - 1; i++) {
        long double p = coef[i + 1];
        for (int j = 0; j <= i; j++) {
            p *= (t - x[j]);
        }
        ans += p;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<long double> x(n), y(n);
    for (auto &u : x) cin >> u;
    for (auto &u : y) cin >> u;
    vector<long double> coef = dif_div(x, y);
    cout << setprecision(15) << fixed;
    for (auto u : coef) cout << u << ',';
    cout << '\n';
    for (;;) {
        long double t;
        cin >> t;
        cout << poly(t, x, coef) << '\n';
    }
}





