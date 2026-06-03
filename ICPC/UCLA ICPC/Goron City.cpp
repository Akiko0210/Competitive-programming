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
    int N, M, G, t;
    cin >> N >> M >> G >> t;
    vector<int> a(N), b(M), c(G);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < G; i++) {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    if(a[N - 1] > c[G - 1] || b[M - 1] > c[G - 1]) {
        cout << "-1";
        return;
    }

    ll l = 0, r = (ll)t * M + N;
    while(l < r) {
        int m = (l + r) / 2;
        int p1 = 0, p2 = 0;
        for(int worker : c) {
            ll curtime = 0;
            while(p2 < M && b[p2] <= worker && curtime + t <= m) {
                p2++;
                curtime += t;
            }

            while(p1 < N && a[p1] <= worker && curtime + 1 <= m) {
                p1++;
                curtime += 1;
            }
        }
        if(p1 == N && p2 == M) {
            // can
            r = m;
        } else {
            // can't
            l = m + 1;
        }
    }
    cout << l << "\n";
}

int main() {
    FAST
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

