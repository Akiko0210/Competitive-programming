#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT64_MAX
using namespace std;
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef AKIKO_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif


#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 1e9 + 7;

void solve() {
    ll base_cost = 1e12 + 1;
    string s;
    cin >> s;
    int n = s.size();

    vector<int> ind;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') ind.pb(i);
    }

    ll cnt = ind.size();
    if(cnt == 0) {
        cout << "0\n";
        return;
    }
    ll ans = cnt * base_cost;
    for(int i = 0; i < cnt; i++) {
        ll cost = base_cost * (cnt - i - 1 + ind[i] - i);
        if(i > 0) {
            cost -= ind[i] - ind[i - 1] - 1;
        } else {
            cost -= ind[i];
        }
        ans = min(ans, cost);
    }
    cout << ans << "\n";
    // vector<ll> sum(n, 0);
    // ll cursum = 0, cnt = 0;
    // for(int i = 0; i < n; i++) {
    //     cnt += s[i] - '0';
    //     if(s[i] == '0') {
    //         cursum += cnt;
    //         sum[i] = cursum;
    //     }
    // } 

    // for(int i = 0; i <= n - cnt; i++) {
    //     // in case we have i 0s

    // }

    // for(int x : sum) {
    //     cout << x << " ";
    // }
    // cout << "\n";

}

int main() {
    int t;
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
