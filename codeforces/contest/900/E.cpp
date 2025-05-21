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
    int n, max_bit = 31;
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > dp(n, vector<int> (max_bit, 0));

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][0] = a[i];
    }
    
    for(int i = 1; i < max_bit; i++) {
        for(int j = 0; j < n; j++) {
            int x = min(n - 1, j + (1 << (i - 1)));
            
            dp[j][i] = dp[j][i - 1] & dp[x][i - 1];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, k, cur = (1 << max_bit) - 1;
        cin >> l >> k;
        l--;
        if(a[l] < k) {
            cout << "-1 ";
            continue;
        }
        
        for(int i = max_bit - 1; i >= 0; i--) {
            if(l < n && (cur & dp[l][i]) >= k) {
                cur &= dp[l][i];
                l += (1 << i);
            }
        }
        cout << min(l, n) << " ";
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
