#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> res(n);
    for(int i = 0; i < n; i++) cin >> res[i];
    
    int mx = 0;
    for(int mask = 0; mask < (1 << k); mask++) {
        string ans = "";
        for(int i = 0; i < k; i++) {
            ans += ((mask & (1 << i)) ? 'T' : 'F');
        }

        int mn = k;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < k; j++) {
                cnt += (res[i][j] == ans[j]);
            }
            mn = min(mn, cnt);
        }
        mx = max(mx, mn);
    }
    cout << mx << "\n";

    return 0;
}