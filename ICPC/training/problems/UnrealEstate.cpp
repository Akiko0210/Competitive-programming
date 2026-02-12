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

int main() {
    int n;
    cin >> n;
    map<double, vector<pair<double, int > > > m;
    vector<double> xs;
    for(int i = 0; i < n; i++) {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xs.pb(x1);
        xs.pb(x2);
        m[y1].pb({x1, 1});
        m[y1].pb({x2, -1});
        m[y2].pb({x1, -1});
        m[y2].pb({x2, 1});
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    unordered_map<double, int> xind;
    int len = xs.size();
    for(int i = 0; i < len; i++) {
        xind[xs[i]] = i;
    }

    vector<int> sweep(len, 0);
    double ans = 0, prey = -1e9, preactive = 0;
    for(auto &[y, pos] : m) {
        for(auto &[x, val] : pos) {
            sweep[xind[x]] += val;
        }
        vector<int> sum = sweep;
        double active = 0;
        for(int i = 1; i < len; i++) {
            active += (xs[i] - xs[i - 1]) * (sum[i - 1] > 0);
            sum[i] += sum[i - 1];
        }
        ans += (y - prey) * preactive;
        preactive = active;
        prey = y;
    }

    cout << fixed << setprecision(2) << ans << "\n";

    return 0;
}
