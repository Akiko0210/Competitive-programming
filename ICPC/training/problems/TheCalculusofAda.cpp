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

pii solve(vector<int> a) {
    bool cons = true;
    for(int i = 1; i < a.size(); i++) {
        if(a[i] != a[i - 1]) {
            cons = false;
            break;
        }
    }

    if(cons) {
        return {0, a[0]};
    }

    vector<int> d;
    for(int i = 1; i < a.size(); i++) {
        d.pb(a[i] - a[i - 1]);
    }

    auto [deg, dx] = solve(d);
    return {deg + 1, a.back() + dx};
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pii ans = solve(a);
    cout << ans.ff << " " << ans.ss << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

