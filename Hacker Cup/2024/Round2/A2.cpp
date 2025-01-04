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

vector<vector<ll> > mountains(9);
vector<vector<ll> > reverse_mountains(9);
vector<ll> pws(18);

ll to_num(vector<int> d) {
    reverse(d.begin(), d.end());
    ll ans = 0;
    while(!d.empty()) {
        ans = ans * 10 + d.back();
        d.pop_back();
    }
    return ans;
}

void rec(vector<int>& d, int i, int c) {
    if(i == d.size()) {
        mountains[d.size()].pb(to_num(d));
        return;
    }

    for(int cur = c; cur <= 8; cur++) {
        d[i] = cur;
        rec(d, i + 1, cur);
    }
}

void reverse_rec(vector<int>& d, int i, int c) {
    if(i == d.size()) {
        reverse_mountains[d.size()].pb(to_num(d));
        return;
    }

    for(int cur = 1; cur <= c; cur++) {
        d[i] = cur;
        reverse_rec(d, i + 1, cur);
    }
}

void prebuild() {
    for(int i = 1; i <= 8; i ++) {
        vector<int> d(i);
        rec(d, 0, 1);
    }

    for(int i = 1; i <= 8; i ++) {
        vector<int> d(i);
        reverse_rec(d, 0, 8);
    }


    ll cur = 1;
    for(int i = 0; i < 18; i++) {
        pws[i] = cur;
        cur *= 10;
    }
}

void solve() {
    ll a, b, m, cnt = 0;
    cin >> a >> b >> m;
    for(int len = 0; len < 9; len++) {
        for(ll fh : mountains[len]) {
            for(ll d = fh % 10 + 1; d <= 9; d++) {
                for(ll sh : reverse_mountains[len]) {
                    if(len > 0 && sh / pws[len - 1] >= d) break;

                    ll fn = fh * pws[len + 1] + d * pws[len] + sh;
                    if(fn > b) {
                        cout << cnt << "\n";
                        return;
                    }
                    if(fn < a) continue;

                    // debug(fn, fh, d, sh);
                    if(fn % m == 0) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << "\n";
}

int main() {
    prebuild();
    mountains[0].pb(0);
    reverse_mountains[0].pb(0);

    // for(int i = 1; i < 3; i++) {
    //     debug(i, mountains[i].size());
    //     for(int x : mountains[i]) {
    //         cout << x << " mt\n";
    //     }
    //     cout << "-----\n";
    //     for(int x : reverse_mountains[i]) {
    //         cout << x << " rt\n";
    //     }
    // }

    int t = 1;
    cin >> t;
    for(int _ = 1; _ <= t; _++) {
        cout << "Case #" << _ << ": ";
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

