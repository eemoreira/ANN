#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* given f(x), isolate it in a way such that u end up with something like x = g[x] */
/* transition of the form x[n] = g[x[n-1]] */
/* ONLY CONVERGES IF abs(g'[root]) < 1!!!!!! */
void solve() {
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double a;
    cin >> a;
    auto g = [&](double x) {
        return sqrt((x + 3) / (x*x + 2));
    };
    auto f = [&](double x) {
        return x * x * x * x + 2 * x * x - x - 3;
    };
    cout << setprecision(15) << fixed;
    for (int i = 0; i < 8; i++) {
        a = g(a);
        cout << i << ' ' << a << ' ' << f(a) << '\n';
    }
}





