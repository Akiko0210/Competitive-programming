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

class Segtree {
    private: 
        int L;
        vector<vector<int> > stree;

        void build(int i, int L, int R, vector<int>& a) {
            if(L == R) {
                stree[i] = {a[L]};
                return;
            }
            int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
            build(x, L, M, a);
            build(y, M + 1, R, a);
            stree[i] = merge(stree[x], stree[y]);
        }

        vector<int> merge(vector<int>& a, vector<int>& b) {
            int n = a.size(), m = b.size(), i = 0, j = 0;
            vector<int> c(n + m);
            while(i < n && j < m) {
                if(a[i] < b[j]) {
                    c[i + j] = a[i];
                    i++;
                }
                else {
                    c[i + j] = b[j];
                    j++;
                }
            }

            while(i < n) {
                c[i + j] = a[i];
                i++;
            } 
            while(j < m) {
                c[i + j] = b[j];
                j++;
            }
            
            return c;
        }
        int query(int i, int L, int R, int l, int r, int val) {
            if(l <= L && R <= r) {
                int res = lower_bound(stree[i].begin(), stree[i].end(), val) - stree[i].begin();
                return res;
            }
            int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2, lval = 0, rval = 0;
            if(l <= M) {
                lval = query(x, L, M, l, r, val);
            }
            if(r > M) {
                rval = query(y, M + 1, R, l, r, val);
            }
            return lval + rval;
        }
        
    public: 
        Segtree (vector<int> a) {
            L = a.size();
            stree.resize(L * 4);
            build(0, 0, L - 1, a);
        }
        int query(int l, int r, int val) {
            return query(0, 0, L - 1, l, r, val);
        }
        void print() {
            print(0, 0, L - 1);
        }
        void print(int i, int L, int R) {
            cout << i << " from " << L << " " << R << "\n";
            for(int x : stree[i]) {
                cout << x << " ";
            }
            cout << "\n";
            if(L == R) {
                return;
            }
            int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
            print(x, L, M);
            print(y, M + 1, R);
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), prev(n), last(m + 1, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        prev[i] = last[a[i]];
        last[a[i]] = i;
    }

    ll ans = 0;
    Segtree s(prev);
    for(int i = 0; i < n; i++) {
        if(prev[i] == -1) {
            ans += m - 1;
        } else {
            ans += s.query(prev[i], i, prev[i]) - 1;
        }
    }

    cout << ans << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

