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

struct Stree {
    int n;
    vector<vector<int> > lazy;
    vector<vector<int> > cnt;

    Stree(int n) {
        this->n = n;
        for(int i = 0; (1 << i) <= n; i++) {
            lazy.push_back(vector<int> (n * 4, 0));
            cnt.push_back(vector<int> (n * 4, 0));
        }
    }

    int adjust(int p, int l, int start, int r) {
        return start + ((((r - l - 1) >> (p + 1)) + 1) << (p + 1));
        // return ((l >> (p + 1)) << (p + 1)) + (1 << p);
    }

    void add(int l, int r) {
        for(int i = 0; i < lazy.size(); i++) {
            update(i, 0, 0, n - 1, l + (1 << i) - 1, r, (1 << i));
        }
    }

    // void propagate(int p, int i, int L, int R) {
    //     int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    //     if(lazy[p][i] > 0) {
    //         lazy[p][x] += lazy[p][i];
    //         int adjusted = lazy[p][i] + (M - L - 1)
    //     }
    // }

    void update(int p, int i, int L, int R, int l, int r, int start) {
        // debug(p, i, L, R, l, r, start);
        if(l > r) return;
        // if(!(l & (1 << p))) {
        //     update(p, i, L, R, fix(p, l), r, start);
        //     return;
        // }

        if(l == L && R == r) {
            lazy[p][i] += start;
            cnt[p][i]++;
            return;
        }

        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        if(l <= M) {
            update(p, x, L, M, l, min(M, r), start);
        }
        if(r > M) {
            // p = 1, l = 2, newl = 5 -> newstart = 6.
            int newStart = adjust(p, l, start, max(l, M + 1));
            update(p, y, M + 1, R, newStart - start + l, r, newStart);
        }
    }

    ll find(int ind) {
        ll res = 0;
        for(int i = 0; i < lazy.size(); i++) {
            ll val = find(i, 0, 0, n - 1, ind);
            // debug(ind, i, val);
            res += val * (1 << i);
        }
        return res;
    }

    ll find(int p, int i, int L, int R, int ind) {
        if(L == R) {
            return lazy[p][i];
        }
        ll res = 0;
        if((ind - L) % (1 << (p + 1)) == 0) {
            // on the line.
            if(lazy[p][i] > 0) {
                res += (ll)lazy[p][i] + (ll)(ind - L) * cnt[p][i];
            }
        }
        int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
        if(ind <= M) {
            res += find(p, x, L, M, ind);
        } else {
            res += find(p, y, M + 1, R, ind);
        }

        return res;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    Stree st(n);
    while(q--) {
        int l, r;
        cin >> l >> r;
        st.add(l - 1, r - 1);
    }

    for(int i = 0; i < n; i++) {
        cout << st.find(i) << " ";
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

