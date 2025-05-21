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


struct Solver {
    vector<vector<int> > dp;
    vector<ll> a;
    vector<ll> pre;
    int n, ans;
    

    Solver(vector<ll> ar) {
        ans = 0;
        a = ar;
        n = a.size();
        pre.resize(n);
        for(int i = 0; i < n; i++) {
            pre[i] = a[i];
            if(i > 0) pre[i] += pre[i - 1];
        }

        dp.resize(n, vector<int> (20));
        for(int i = 0; i < n; i++) {
            dp[i][0] = i;
        }

        for(int j = 1; j < 20; j++) {
            for(int i = 0; i < n; i++) {
                if(i + (1 << j) <= n) {
                    int l = dp[i][j - 1], r = dp[i + (1 << (j - 1))][j - 1];
                    dp[i][j] = a[l] > a[r] ? l : r;
                }
            }
        }
    }

    int maxinrange(int l, int r) {
        l++, r--;
        
        int len = r - l + 1, cnt = 0;
        while((1 << (cnt + 1)) <= len) {
            cnt++;
        }
        if(a[dp[l][cnt]] > a[dp[r - (1 << cnt) + 1][cnt]]) {
            return dp[l][cnt];
        }

        return dp[r - (1 << cnt) + 1][cnt];
    }

    ll rangesum(int l, int r) {
        ll sub = l >= 0 ? pre[l] : 0, sum = pre[r - 1] - sub;
        return sum;
    }

    void solve(int l, int r, int val) {
        if(l >= r - 1) return;
        ll sum = rangesum(l, r);
        if(sum >= val) {
            ans++;
            int mxind = maxinrange(l, r);
            solve(l, mxind, a[mxind]);
            solve(mxind, r, a[mxind]);
            return;
        }
    }

    int getans() {
        return ans;
    }

};

void solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Solver s(a);
    s.solve(-1, n, 0);
    cout << s.getans() << "\n";
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

