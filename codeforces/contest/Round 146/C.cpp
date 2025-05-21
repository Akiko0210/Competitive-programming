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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pii> r(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i].ff;
        r[i].ss = i + 1;
    }

    sort(r.rbegin(), r.rend());
    vector<int> a, b;
    int lp = 0, rp = 0;
    for(int i = 0; i < n; i++) {
        if((lp + 1) * s1 < (rp + 1) * s2) {
            a.pb(r[i].ss);
            lp++;
        }  else {
            b.pb(r[i].ss);
            rp++;
        }
    }
    cout << a.size() << " ";
    for(int x : a) {
        cout << x << " ";
    }
    cout << "\n" << b.size() << " ";
    for(int x : b) {
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
