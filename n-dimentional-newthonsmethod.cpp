#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

// X[n] = X[n - 1] - F'[X[n]]^-1 * F[X[n]]
// where F'[X[n]]^1 is the inverse of the jacobian of F aplied to X[n]
typedef vector<vector<long double>> mat;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto mul = [&](mat x, mat y) {
        mat ans((int)x.size(), vector<long double>((int)y[0].size()));
        for (int i = 0; i < (int)x.size(); i++) {
            for (int j = 0; j < (int)y[0].size(); j++) {
                for (int k = 0; k < (int)x[0].size(); k++) {
                    ans[i][j] += (x[i][k] * y[k][j]);
                }
            }
        }
        return ans;
    };
    auto f1 = [&](long double x, long double y) {
        return y - x * x - 1;
    };
    auto f2 = [&](long double x, long double y) {
        return x * x + y * y - 5;
    };
    auto Df1x = [&](long double x, long double y = 0) {
        return -2 * x;
    };
    auto Df1y = [&](long double x = 0, long double y = 0) {
        return (long double)1;
    };
    auto Df2x = [&](long double x, long double y = 0) {
        return 2 * x;
    };
    auto Df2y = [&](long double x = 0, long double y) {
        return 2 * y;
    };
    auto det = [&](mat F) {
        return (long double) F[0][0] * F[1][1] - F[0][1] * F[1][0];
    };
    mat X = {
        {2},
        {3}
    };
    auto inverseJacobian = [&]() {
        long double x = X[0][0];
        long double y = X[1][0];
        mat F = {{Df1x(x,y), Df1y(x,y)}, {Df2x(x,y), Df2y(x,y)}};
        long double dt = 1 / det(F);
        mat ans = {{Df2y(x,y), -Df2x(x,y)}, {-Df1y(x,y), Df1x(x,y)}};
        for (auto &u : ans) {
            for (auto &l : u) {
                l *= dt;
            }
        }
        return ans;
    };
    for (int i = 0; i < 50; i++) {
        mat now = inverseJacobian();
        mat nowF = { 
            {f1(X[0][0],X[1][0])}, 
            {f2(X[0][0],X[1][0])}
        };
        mat nowmult = mul(now, nowF);
        X[0][0] -= nowmult[0][0];
        X[1][0] -= nowmult[1][0];
    }
    cout << setprecision(10) << fixed;
    cout << X[0][0] << ' ' << X[1][0] << '\n';
}





