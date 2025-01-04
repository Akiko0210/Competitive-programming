#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef AKIKO_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll presum = 0, cnt1 = 0, cnt2 = 0, ans = 0;
    for(int &x : a) {
        cin >> x;
        presum += x;
    }

    ll sum = presum;
    if(sum % 3) {
        cout << "0\n";
        return;
    }

    presum = 0;
    for(int i = 0; i < n - 1; i++) {
        presum += a[i];
        if(presum == sum / 3 * 2) {
            ans += cnt1;
            cnt2++;
        }
        if(presum == sum / 3) {
            cnt1++;
        }
    }

    cout << ans << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

