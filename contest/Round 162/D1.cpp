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

vector<int> calc(int n, vector<ll>& a) {
    vector<vector<bool> > canmerge(20, vector<bool> (n, false));
    vector<vector<ll> > sum(20, vector<ll> (n, 0));
    for(int i = 0; i < n; i++) {
        sum[0][i] = a[i];
        canmerge[0][i] = false;
    }

    for(int i = 1; i < 20; i++) {
        for(int j = 0; j < n; j++) {
            if(j + (1 << i) <= n) {
                int l = j + (1 << (i - 1));
                // [0][2] [0][3] [1][2] -> [2, 3]
                sum[i][j] = sum[i - 1][j] + sum[i - 1][l];
                canmerge[i][j] = (sum[i - 1][j] != sum[i - 1][l] || canmerge[i - 1][j] || canmerge[i - 1][l]);
            }
        }
    }

    vector<int> ans(n, INF);
    for(int i = 0; i < n; i++) {
        debug(i);
        if(i < n - 1 && a[i] < a[i + 1]) {
            ans[i] = 1;
            continue;
        }
        ll cur = i + 1, cursum = 0;
        bool mymerge = false;
        for(int j = 19; j >= 0; j--) {
            if(cur + (1 << j) > n) continue;
            debug(cur, mymerge, cursum);
            if(!(mymerge | canmerge[j][cur]) || cursum + sum[j][cur] <= a[i]) {
                cursum += sum[j][cur];
                mymerge = mymerge | canmerge[j][cur];
                cur += (1 << j);
            }
        }
        if(cur < n)
            ans[i] = cur - i;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // cout << "right:\n";
    vector<int> r = calc(n, a);
    // for(int x : r) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    reverse(a.begin(), a.end());
    vector<int> l = calc(n, a);

    reverse(l.begin(), l.end());
    // cout << "left:\n";
    // for(int x : l) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    
    for(int i = 0; i < n; i++) {
        int ans = min(r[i], l[i]);
        cout << (ans == INF ? -1 : ans) << " ";
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

