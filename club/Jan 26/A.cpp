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

int main() {
    int n, x;
    cin >> n >> x;
    vector<pii> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;

    while(l < r) {
        if(a[l].ff + a[r].ff > x) {
            r--;
            continue;
        }
        if(a[l].ff + a[r].ff < x) {
            l++;
            continue;
        }
        // debug(a[l], a[r]);
        cout << a[l].ss << " " << a[r].ss << "\n";
        return 0;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

 