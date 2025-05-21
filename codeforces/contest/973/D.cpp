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
    vector<ll> a(n);
    vector<pair<ll, ll> > s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s.pb({a[0], 1});
    for(int i = 1; i < n; i++) {
        ll cnt = 1, sum = a[i];
        while(s.size() > 0 && s.back().first > sum / cnt) {
            sum += s.back().first * s.back().second;
            cnt += s.back().second;
            s.pop_back();   
        }
        ll rem = sum % cnt;
        s.pb({sum / cnt, cnt - rem});
        if(rem > 0) {
            s.pb({sum / cnt + 1, rem});
        }
    }

    cout << s.back().ff - s[0].ff << "\n";
    
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

