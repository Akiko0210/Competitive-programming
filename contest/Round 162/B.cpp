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
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ss;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff;
        if(a[i].ff < 0) a[i].ff *= -1;
    }

    sort(a.begin(), a.end());
    ll save = 0, cur = 0;
    for(int i = 0; i < n; i++) {
        save += (a[i].first - cur) * k;
        if(save < a[i].second) {
            cout << "NO\n";
            return;
        }
        save -= a[i].second;
        cur = a[i].first;
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
