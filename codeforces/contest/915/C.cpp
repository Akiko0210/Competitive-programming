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
    /*
    aczb
    acbz
    
    */
    int n;
    string s;
    cin >> n >> s;
    vector<int> ar(n);
    ar[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--) {
        ar[i] = s[i] >= s[ar[i + 1]] ? i : ar[i + 1];
    }

    // for(int x : ar) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    vector<int> inds;
    int cur = 0;
    while(cur < n - 1) {
        // debug(cur);
        inds.pb(ar[cur]);
        cur = ar[cur] + 1;
    }
    if(cur == n - 1)
        inds.pb(cur);

    // for(int x : inds) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    int m = inds.size();
    int cnt = 1;
    for(int i = 1; i < m; i++) {
        if(s[inds[i]] == s[inds[i - 1]]) {
            cnt++;
        } else {
            break;
        }
    }
    for(int i = 0; i < m / 2; i++) {
        swap(s[inds[i]], s[inds[m - 1 - i]]);
    }

    // debug(s);
    for(int i = 1; i < n; i++) {
        if(s[i] < s[i - 1]) {
            cout << "-1\n";
            return;
        }
    }
    cout << inds.size() - cnt << "\n";
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

