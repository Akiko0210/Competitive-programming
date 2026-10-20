#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    sort(a.begin(), a.end());

    long long ans = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1] + 1) ans += a[i];
    }

    cout << ans << "\n";

    return 0;
}