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

struct Seg {
    int n;
    vector<int> seg, p;
    function<bool(int, int)> eval;

    Seg(vector<int>& p, function<bool(int, int)>& evaluator) {
        eval = evaluator;
        n = p.size();
        seg.resize(n * 4);
        this->p = p;
        build(0, 0, n - 1);
    }

    void build(int i, int L, int R) {
        if(L == R) {
            seg[i] = L;
            return;
        }

        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        build(x, L, M);
        build(y, M + 1, R);

        if(eval(p[seg[x]], p[seg[y]])) {
            seg[i] = seg[x];
        } else {
            seg[i] = seg[y];
        }
    }

    void update(int i, int L, int R, int ind, int val) {
        if(L == R) {
            p[L] = val;
            seg[i] = L;
            return;
        }
        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        if(ind <= M) {
            update(x, L, M, ind, val);
        } else {
            update(y, M + 1, R, ind, val);
        }

        if(eval(p[seg[x]], p[seg[y]])) {
            seg[i] = seg[x];
        } else {
            seg[i] = seg[y];
        }
    }

    int find(int i, int L, int R, int l, int r) {
        if(l <= L && R <= r) {
            return seg[i];
        }
        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        if(r <= M) {
            return find(x, L, M, l, r);
        } else if(l > M) {
            return find(y, M + 1, R, l, r);
        }
        int lval = find(x, L, M, l, r);
        int rval = find(y, M + 1, R, l, r);
        if(eval(p[lval], p[rval])) {
            return lval;
        }
        return rval;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(int &x : p) cin >> x;

    function<bool(int, int)> mn = [](int a, int b) {
        return a < b;
    };
    function<bool(int, int)> mx = [](int a, int b) {
        return a > b;
    };
    Seg smn(p, mn);
    Seg smx(p, mx);

    while(m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int a = smn.find(0, 0, n - 1, l, r);
        int b = smx.find(0, 0, n - 1, l, r);
        swap(p[a], p[b]);
        smn.update(0, 0, n - 1, a, p[a]);
        smn.update(0, 0, n - 1, b, p[b]);
        smx.update(0, 0, n - 1, a, p[a]);
        smx.update(0, 0, n - 1, b, p[b]);
    }

    for(int x : p) cout << x << " ";
    cout << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

