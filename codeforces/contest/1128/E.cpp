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

struct Segtree {
    int n;
    vector<int> mx, lazy;
    Segtree(int n) {
        this->n = n;
        mx.resize(n * 4, 0);
        lazy.resize(n * 4, 0);
    }

    void propagate(int i) {
        int x = i * 2 + 1, y = i * 2 + 2;
        if(lazy[i] != 0) {
            lazy[x] += lazy[i];
            lazy[y] += lazy[i];
            lazy[i] = 0;
        }
    }

    void update(int i, int L, int R, int l, int r, int val) {
        if(l <= L && R <= r) {
            lazy[i] += val;
            return;
        }

        propagate(i);

        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        if(l <= M) {
            update(x, L, M, l, r, val);
        }
        if(r > M) {
            update(y, M + 1, R, l, r, val);
        }

        mx[i] = max(mx[x] + lazy[x], mx[y] + lazy[y]);
    }

    int query(int i, int L, int R, int l, int r) {
        if(l > r) return 0;
        if(l <= L && R <= r) {
            return mx[i] + lazy[i];
        }
        propagate(i);

        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2, lval = -INF, rval = -INF;
        if(l <= M) {
            lval = query(x, L, M, l, r);
        }

        if(r > M) {
            rval = query(y, M + 1, R, l, r);
        }

        return max(lval, rval);
    }
};

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> cnt;
    int cur = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            cnt.pb(cur);
            cur = 1;
        } else {
            cur++;
        }
    }
        
    cnt.pb(cur);
    int m = cnt.size() / 2;
    Segtree st(m);
    int prevclose = 0, ans = 0, clsum = 0, opsum = 0, l = 0;
    // starts with (
    for(int i = 0; i < cnt.size(); i += 2) {
        ans = max(ans, cnt[i]);
        // i is always (
        // if(prevclose <= k) {
        //     int mycur = cnt[i] + k;
        //     ans = max(ans, mycur);
        //     prevclose += cnt[i + 1];
        // } else {
            // can't become the first but can steal from the prevs. 
        while(clsum > k) {
            int cl = cnt[l * 2 + 1], op = cnt[l * 2];
            l++;
            clsum -= cl;
            opsum -= op;
        }

        int refund = 0;
        if(l == 0) {
            // gets refund for clsum
            refund = k;
        }

        int mx = st.query(0, 0, m - 1, l, i / 2 - 1);
        ans = max(ans, mx + cnt[i] + refund);
        // }

        st.update(0, 0, m - 1, 0, i / 2, cnt[i] - cnt[i + 1]);
        clsum += cnt[i + 1];
        opsum += cnt[i];
    }

    cout << min(ans, n / 2) << "\n";

    /*
    ((((()((()))))))
    
    */


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

