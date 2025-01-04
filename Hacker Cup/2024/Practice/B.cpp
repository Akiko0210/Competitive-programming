#include <bits/stdc++.h>

using namespace std;

void printans (int t, double ans) {
    cout << "Case #" << t << ": " << fixed << setprecision(8) << ans << "\n";
}

double solve() {
    int n;
    double p, chance = 1.0;
    cin >> n >> p;
    p /= 100.0;

    return (pow(p, (double)(n - 1) / n) - p) * 100;
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        printans(i, solve());
    }

    return 0;
}