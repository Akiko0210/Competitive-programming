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

class SegTree {
    private:
        vector<int> cnt, sum;
        int mn, mx;
    public:
        SegTree (int L, int R) {
            int n = R - L;
            mn = L;
            mx = R;
            cnt.resize(n * 4, 0);
            sum.resize(n * 4, 0);
        }

        void update(int l, int r, int val) {
            update(0, mn, mx, l, r, val);
        }

        void update(int i, int L, int R, int l, int r, int val) {
            // if(L == R) return;
            if(L + 1 == R) {
                cnt[i] += val;
                sum[i] = (cnt[i] > 0);
                return;
            }
            // R > L + 1;
            // full cover
            int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
            if(l <= L && R <= r) {
                cnt[i] += val;
            } else {
                if(l < M) update(x, L, M, l, r, val);
                if(r > M) update(y, M, R, l, r, val);
            }

            if(cnt[i] > 0) {
                sum[i] = R - L;
            } else {
                sum[i] = sum[x] + sum[y];
            }
        }

        int active() {
            return sum[0];
        }
};

int main() {
    int n, mx = INT_MIN, mn = INT_MAX;
    cin >> n;
    map<int, vector<tuple<int, int, int> > > m;
    for(int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int X1, Y1, X2, Y2;
        X1 = int(round(x1 * 100));
        X2 = int(round(x2 * 100));
        Y1 = int(round(y1 * 100));
        Y2 = int(round(y2 * 100));
        m[Y1].pb({X1, X2, 1});
        m[Y2].pb({X1, X2, -1});
        mx = max(mx, X2);
        mn = min(mn, X1);
    }
    SegTree st(mn, mx);
    long long ans = 0, preactive = 0, prey = -1e9;
    for(auto &[y, info] : m) {
        for(auto [l, r, val] : info) {
            st.update(l, r, val);
        }

        int active = st.active();
        ans += preactive * (y - prey);
        preactive = active;
        prey = y;
    }
    cout << fixed << setprecision(2) <<  double(ans) / 10000 << "\n";

    return 0;
}
