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
    int n, d;
    cin >> n >> d;
    vector<ll> a(n), presum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        presum[i] = a[i];
        if(i > 0) {
            presum[i] += presum[i - 1];
        }
    }
    /*
    we wanna make friend i with larger a[i] happy as possible. 
    if i gets a gift the total:
        for every j that didn't receive a gift -> a[i] - a[j]
        for every j that did receive a gift -> no change
    if i doesn't get a gift: 
        for every j that didn't receive a gift -> no change
        for every j that did receive a gift -> a[j] - a[i]

    1 2 3
    2 1 3  = 6 / 2 = 3

    no need to consider if I doesn't get a gift case. 

    */ 
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll sum = 0;
        if(i - d >= 0 && i + d < n) {
            sum = presum[i + d] - (i - d == 0 ? 0 : presum[i - d - 1]);
        } else if(i - d < 0) {
            sum = presum[i + d] + presum[n - 1] - presum[n - 1 + i - d];
        } else {
            sum = presum[n - 1] - presum[i - d - 1] + presum[i + d - n];
        }
        if(sum - a[i] * (d * 2 + 1) > 0) {
            ans += sum - a[i] * (d * 2 + 1);
        }
    }
    cout << ans << "\n";
    

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

