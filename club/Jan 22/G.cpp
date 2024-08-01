#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());
    int l = 0, r = n - 1, ans = 0;
    while(l < r) {
        ans++;
        if(p[r] + p[l] <= x) {
            r--, l++;
            continue;
        }
        r--;
    }
    if(l == r) {
        ans++;
    }
    cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

