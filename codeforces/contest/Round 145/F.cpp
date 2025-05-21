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

const ll MOD = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ind;


    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] == 1) ind.pb(i); 
    }

    int m = ind.size();
    vector<ll> pnt(n, 0), p(n, 0), prev(n, 0);
    for(int i = 0; i < m; i++) {
        ll sum = 0;
        for(int j = (ind[(i + 1) % m] - 1 + n) % n; j != ind[i]; j = (j - 1 + n) % n) {
            if(j != ind[i]) {
                prev[j] = ind[i];
                sum += a[j];
            }
            pnt[j] = sum;
        }
    }

    ll costSum = 0;
    for(int i = 0; i < m; i++) {
        ll dist = a[ind[i]] + pnt[(ind[i] + 1) % n];
        ll cost = min(dist, k) + max(dist - k, 0LL) * 2;
        p[ind[i]] = cost;
        costSum += cost;
    }

    if(costSum == 0) {
        for(int i = 0; i < n; i++) 
            costSum += a[i];
        
        for(int i = 0; i < n; i++) 
            cout << costSum * 2 << " ";
        
        cout << "\n";
        return;
    }

    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        if(b[i] == 1) {
            ans[i] = costSum;
        } else {
            ll dist = a[prev[i]] + pnt[(prev[i] + 1) % n] - pnt[i];
            ans[i] = costSum - p[prev[i]] + pnt[i] * 2 + min(dist, k) + max(dist - k, 0LL) * 2;
        }
    }

    for(ll x : ans) {
        cout << x << " ";
    }
    cout << "\n";



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
