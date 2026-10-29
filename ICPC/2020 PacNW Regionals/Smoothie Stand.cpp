#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, r;
    cin >> k >> r;
    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];


    long long ans = 0;
    for(int i = 0; i < r; i++) {
        int mn = 1e9;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if(x > 0)
                mn = min(mn, a[j] / x);
        }
        long long cost;
        cin >> cost;
        ans = max(ans, cost * mn);
    }
    cout << ans << "\n";

    return 0;
}