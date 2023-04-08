#include <bits/stdc++.h>

using namespace std;
typedef tuple<int,int,int> i3;
typedef long long ll;
typedef long double ld;
typedef vector<vector<ld>> mat;

mat mul(mat& x, mat& y) {
    mat ans((int)x.size(), vector<long double>((int)y[0].size()));
    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = 0; j < (int)y[0].size(); j++) {
            for (int k = 0; k < (int)x[0].size(); k++) {
                ans[i][j] += (x[i][k] * y[k][j]);
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    mat a(n, vector<ld>(m));
    vector<ld> x(n), b(n);
    for (int i = 0; i < n; i++) {
        for (auto &u : a[i]) {
            cin >> u;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << setprecision(15) << fixed;
    for (int i = 1; i <= 30; i++) {
        vector<ld> prev = x;
        for (int j = 0; j < n; j++) {
            x[j] = b[j];
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                x[j] -= a[j][k] * prev[k];
            }
            x[j] /= a[j][j];
        }
        cout << i << " -> ";
        for (int j = 0; j < n; j++) cout << x[j] << ",\n"[j + 1 == n];
    }
}





