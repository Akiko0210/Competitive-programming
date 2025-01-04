#include <iostream>

using namespace std;

const int mod = 1e9 +7;

int main () {
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= min(6, i); j++) {
            (dp[i] += dp[i - j]) %= mod;
        }
    }
    cout << dp[n] << "\n";

    return 0;
}