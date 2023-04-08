#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ld>> a(n, vector<ld>(m));
    for (auto &u : a) {
        for (auto &x : u) {
            cin >> x;
        }
    }
    for (int i = 0; i < m; i++) a[1][i] += a[2][i] * 4.0/5;
    for (int i = 0; i < m; i++) swap(a[0][i],a[3][i]);
    for (int i = 0; i < m; i++) a[1][i] -= a[0][i] * 5.0/7;
    for (int i = 0; i < m; i++) a[2][i] *= -5.0/4;
    for (int i = 0; i < m; i++) a[1][i] *= -2.0/7;
    for (int i = 0; i < m; i++) swap(a[1][i],a[3][i]);
    cout << setprecision(15) << fixed;
    for (auto &u : a) {
        for (auto &x : u) {
            cout << x << ',';
        }
    }
    cout << '\n';
}





