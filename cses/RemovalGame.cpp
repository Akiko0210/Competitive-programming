#include <bits/stdc++.h>
#define ll long long
#define INF INT64_MAX

using namespace std;

vector<vector<ll> >  dp(5000, vector<ll> (5000, INF));
ll a[5000];

ll rec(int l, int r, ll sum) {
    if(dp[l][r] != INF) return dp[l][r];
    if(l == r) return dp[l][r] = a[l];

    return dp[l][r] = sum - min(rec(l + 1, r, sum - a[l]), rec(l, r - 1, sum - a[r]));
}

int main () {
    int n;
    cin >> n;
    
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    cout << rec(0, n - 1, sum) << "\n";
}