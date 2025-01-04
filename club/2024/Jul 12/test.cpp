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

class Stree {
    private:
        int n;
        vector<int> a;
        vector<int> st;
        void build(int i, int L, int R) {
            if(L == R) {
                st[i] = a[L];
                return;
            }

            int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;

            build(x, L, M);
            build(y, M + 1, R);
            st[i] = st[x] + st[y];
        }

        void update(int i, int L, int R, int ind, int val) {
            if(L == R) {
                a[L] = val;
                return;
            }
            int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
            if(M < ind) {
                update(x, M + 1, R, ind, val);
            } else {
                update(y, L, M, ind, val);
            }

            st[i] = st[x] + st[y];
        }

        int query(int i, int L, int R, int l, int r) {
            if(l <= L && R <= r) {
                return st[i];
            }
            int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
            int lval = 0, rval = 0;
            if(l <= M) {
                lval = query(x, L, M, l, r);
            }
            if(r > M) {
                rval = query(y, M + 1, R, l, r);
            }

            return lval + rval;
        }

    public:
        Stree(int n, vector<int>& arr) {
            st.resize(n * 4, 0);
            a = arr;
            build();
        }

        void build() {
            build(0, 0, n - 1);
        }

        void update(int ind, int val) {
            update(0, 0, n - 1, ind, val);
        }

        int query(int l, int r) {
            return query(0, 0, n - 1, l, r);
        }
};

class Hash {

};

int main() {
    long long n, mod = 1e9 + 9, p = 151993, cur = 0;
    int n;

    vector<long long> hashes(n), powers(n, 1);
    for(int i = 0; i < n; i++) {
        cur = (cur * p + target[i]) % mod;
        hashes[i] = cur;
        if(i > 0) {
            powers[i] = (powers[i - 1] * p) % mod;
        }
    }
    
    auto calc = [&] (int l, int r) {
        int len = r - l;
        long long res = (hashes[r] - hashes[l] * powers[len] % mod + mod) % mod;
        return res;
    };


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

