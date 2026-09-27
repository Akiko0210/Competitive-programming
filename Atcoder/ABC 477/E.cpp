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

const int N = 4e5;

struct Segtree {
    int n;
    vector<ll> a, seg;
    Segtree(int n, vector<ll>& given) {
        this->n = n;
        a = given;
        seg.resize(n * 4);

        build(0, 0, n - 1);
    }

    void build(int i, int L, int R) {
        if(L == R) {
            seg[i] = a[L];
            return;
        }

        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        build(x, L, M);
        build(y, M + 1, R);
        seg[i] = min(seg[x], seg[y]);
    }
    
    ll find(int l, int r) {
        return find(0, 0, n - 1, l, r);
    }

    ll find(int i, int L, int R, int l, int r) {
        if(l <= L && R <= r) {
            return seg[i];
        }

        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        ll lval = 1e18, rval = 1e18;
        if(l <= M) {
            lval = find(x, L, M, l, r);
        }
        if(r > M) {
            rval = find(y, M + 1, R, l, r);
        }

        return min(lval, rval);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n), pre(2 * n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < 2 * n; i++) {
        pre[i] = a[i % n];
        if(i > 0) pre[i] += pre[i - 1];
    }

    vector<ll> d1(2 * n), d2 = d1;
    for(int i = 0; i < 2 * n; i++) {
        d1[i] = b[i % n] + (i == 0 ? 0 : pre[i - 1]);
        d2[i] = b[i % n] - (i == 0 ? 0 : pre[i - 1]);
    }

    Segtree s1(2 * n, d1), s2(2 * n, d2);
    auto calc = [&](int l, int r) {
        // just walk right
        ll ans = pre[r - 1] - (l == 0 ? 0 : pre[l - 1]);
        // jump jump walk right
        ans = min(ans, s2.find(l, r) + b[l] + (r == 0 ? 0 : pre[r - 1]));
        // walk jump jump
        ans = min(ans, s1.find(l, r) + b[r] + (l == 0 ? 0 : pre[l - 1]));
        return ans;
    };
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);

        l--, r--;
        if(r == n) {
            // move right then jump
            ll ans = s1.find(l, l + n) - (l == 0 ? 0 : pre[l - 1]);
            l += n;
            // move left then jump
            ans = min(ans, s2.find(l - n, l) + pre[l - 1]);
            cout << ans << "\n";
        } else {
            ll ans = calc(l, r);
            l += n;
            ans = min(ans, calc(r, l));
            cout << ans << "\n";
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

