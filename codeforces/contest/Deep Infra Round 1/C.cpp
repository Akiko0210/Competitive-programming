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

vector<int> rec(int x) {
    if (x == 1) return {1};

    vector<int> a = rec(x / 2);
    vector<int> ans = {x};
    for(int x : a) {
        ans.pb(x);
    }
    ans.pb(x);
    for(int i = a.size() - 1; i > 0; i--) {
        ans.pb(a[i]);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    /*
    use number from 0 ... n
    maximize len(a) - f(a) and maximize len(a)
    then we add an element as long as the new xor = 0 it creates is <= 1.

    */
    
    int x = 0;
    while((1 << (x + 1)) <= n) {
        x++;
    }

    // cout << (1 << (x + 1)) - 1 << "\n";
    // debug(x);
    vector<int> ans = rec(1 << x);
    ans.pb(0);
    for(int i = ans.size() - 2; i >= 0; i--) {
        ans.pb(ans[i]);
    }
    cout << ans.size() << "\n";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}

int main() {
    FAST
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

