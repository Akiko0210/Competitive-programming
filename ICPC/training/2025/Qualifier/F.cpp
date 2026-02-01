#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll sum = 0, sqsum = 0;
    double ans = 2e18;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        sqsum += a[i] * a[i];
        if(i >= k - 1) {
            ans = min(ans, (double)sqsum - (double)sum / (double)k * (double)sum);
            sum -= a[i - k + 1];
            sqsum -= a[i - k + 1] * a[i - k + 1]; 
        }
    }
    cout << setprecision(6) << fixed << ans << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
