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
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a.begin(), a.end(), [](pii x, pii y) -> bool {
        if(x.ff < y.ff) return 1;
        if(x.ff > y.ff) return 0;
        return x.ss > y.ss;
    });

    int cnt = 0, br = 0;
    ll ans = 0;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(a[i].ff <= br) {
            continue;
        } 
        
        q.push(a[i].ff);
        cnt++;
        br = max(br, cnt);
        ans += a[i].ss;
        while(q.size() > 0 && q.front() <= br) {
            cnt--;
            q.pop();
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
