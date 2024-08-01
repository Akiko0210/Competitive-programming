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
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i <= n - 1 - i; i++) {
        if(s[i] != s[n - 1 - i]) {
            cnt ++;
        }
    }
    vector<int> ans(n + 1, 0);
    for(int i = 0; cnt * 2 + i * 2 <= n; i++) {
        ans[cnt + i * 2] = 1;
        if(n & 1) ans[cnt + i * 2 + 1] = 1;
    }
    for(int x : ans) {
        cout << x;
    }
    cout << "\n";

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
