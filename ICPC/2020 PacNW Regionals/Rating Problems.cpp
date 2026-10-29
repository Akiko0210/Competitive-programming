#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    double mn = 0, mx = 0;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        mn += x;
        mx += x;
    }

    mn += -3.0 * (n - k);
    mx += 3.0 * (n - k);
    mn /= n;
    mx /= n;
    cout << fixed << setprecision(6) << mn << " " << mx << "\n";

    return 0;
}