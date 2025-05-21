#include <bits/stdc++.h>

using namespace std;

void solve() {

    /*
    2 3 1 0
    0 1 1

    4 5 4 5 4 5 4 5
    0 1 3 5 4 5 4 5
    0 0 2 5 4 5 4 5
    0 0 0 3 4 5 4 5
    0 0 0 0 1 5 4 5
    0 0 0 0 0 4 4 5

    i > 0
    i, i + 1 will be 0
    a[j] = 0, j < i.
    */
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i + 1 < n; i++) {
        int mn = min(a[i], a[i + 1]);
        a[i] -= mn;
        a[i + 1] -= mn;
        if(a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

