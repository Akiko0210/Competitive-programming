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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    for(int batch = 2; batch <= n; batch++) {
        if(n % batch) continue;

        bool isvalid = true;
        int sz = n / batch, mn = 0, mx = 0, premx = -1;
        for(int i = 0; i < n; i++) {
            if(i % sz == 0) {
                isvalid = isvalid & (mn > premx);
                premx = mx;
                mn = mx = a[i];
            } else {
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
        }
        isvalid = isvalid & (mn > premx);
        if(isvalid) {
            ans.pb(batch);
        }
    }
    if(ans.size() == 0) {
        cout << "-1\n";
    } else {
        for(int x : ans) {
            cout << x << "\n";
        }
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

