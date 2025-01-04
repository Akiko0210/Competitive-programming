#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    int dp[x + 1];
    for(int i = 0; i <= x; i++) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for(int j = 0; j + t <= x; j++) {
            dp[j + t] = min(dp[j + t], dp[j] + 1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << "\n";

    return 0;
}