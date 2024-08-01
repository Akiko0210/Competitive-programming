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
    count y that: f(x, z) < f(x, z) ^ a(y)
    */
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<vector<int> > > pre(n, vector<vector<int> > (31, vector<int> (2, 0))), suf;
    suf = pre;
    for(int j = 0; j < 31; j++) {
        int cnt = 0;
        // pre[0][j][0] = 1;
        for(int i = 0; i < n; i++) {
            if(a[i] & (1 << j)) {
                cnt++;
            }

            if(i > 0) {
                pre[i][j][0] = pre[i - 1][j][0];
                pre[i][j][1] = pre[i - 1][j][1];
            }
            
            pre[i][j][cnt & 1]++;
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int mxbit = 0;
        // debug(a[i]);
        while(a[i] > 0) {
            a[i] >>= 1;
            mxbit++;
        }
        mxbit--;
        ll even = 0, odd = 0;
        // debug(before, after);
        if(i > 0) {
            even += (ll)(pre[n - 1][mxbit][0] - pre[i - 1][mxbit][0]) * (pre[i - 1][mxbit][0] + 1);
            odd += (ll)(pre[n - 1][mxbit][1] - pre[i - 1][mxbit][1]) * pre[i - 1][mxbit][1];
        } else {
            even += pre[n - 1][mxbit][0];
            // after *= pre[n - 1][mxbit][1];
        }
        // debug(even, odd);
        ans += even + odd;




        // ll rem = (pre[n - 1][mxbit][0] - (i > 0 ? pre[i - 1][mxbit][0] : 0));
        // ll sum = ((i > 0 ? pre[i - 1][mxbit][0] : 0) + 1) * rem;
        // debug((i > 0 ? pre[i - 1][mxbit][0] : 0) + 1, rem);
        // rem = (pre[n - 1][mxbit][1] - pre[i][mxbit][1]);
        // sum += (i > 0 ? pre[i - 1][mxbit][1] : 0) * rem;
        // debug(sum, (i > 0 ? pre[i - 1][mxbit][1] : 0), rem);
        // ans += sum;
        // debug(sum, pre[i][mxbit][0], suf[i][mxbit][0], pre[i][mxbit][1], suf[i][mxbit][1]);
        // ans += (ll)pre[i][mxbit][0] * (ll)suf[i][mxbit][0];
        // ans += (ll)pre[i][mxbit][1] * (ll)suf[i][mxbit][1];
    }
    cout << ans << "\n";
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

