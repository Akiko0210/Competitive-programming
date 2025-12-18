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
    FAST
    ll n, k, m, C;
    cin >> n >> k >> m >> C;
    vector<int> a(m);
    unordered_map<int, set<int> > umap;
    vector<int> seating(n, 0);
    for(int i = 0; i < n; i++) {
        umap[0].insert(i);
    }

    auto bigger = [&] (ll n1, ll d1, ll n2, ll d2) {
        if(n1 < n2) {
            while(d2 > 0 && n1 < n2) {
                d2--;
                n1 *= 2;
            }

            if(n1 < n2) {
                return -1;
            }
            if(n1 == n2) {
                return (d1 < d2 ? 1 : d1 == d2 ? 0 : -1);
            }
            // n1 > n2 barely
            return (d1 <= d2 ? 1 : -1);
        }
        // n1 >= n2
        while(d1 > 0 && n2 < n1) {
            d1--;
            n2 *= 2;
        }

        if(n2 < n1) {
            return 1;
        }

        if(n1 == n2) {
            return (d1 < d2 ? 1 : d1 == d2 ? 0 : -1);
        }
        // n2 > n1 barely
        return (d2 <= d1 ? -1 : 1);
    };

    auto consider = [&] (ll cur_row, ll target, ll &ans, ll &row) {
        // C - abs(target - cur_row) / 2^(seating[cur_row]);
        ll n1 = C - abs(target - cur_row);
        ll d1 = seating[cur_row];
        if(ans == -1) {
            ans = n1;
            row = cur_row;
            return;
        }
        ll n2 = ans;
        ll d2 = seating[row];

        int res = bigger(n1, d1, n2, d2);
        if(res == 1) {
            ans = n1; 
            row = cur_row;
        } else if(res == 0) {
            if(row > cur_row) {
                ans = n1;
                row = cur_row;
            }
        }
    };

    for(int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
        ll ans_top = -1, row;
        for(auto &[cnt, rows] : umap) {
            // cnt seating are rows.
            auto it = rows.lower_bound(a[i]);
            if(it == rows.end()) {
                it--;
                consider(*it, a[i], ans_top, row);
            } else if (it == rows.begin()) {
                consider(*it, a[i], ans_top, row);
            } else {
                auto nxt = it;
                it--;
                if(abs(a[i] - *nxt) < abs(a[i] - *it)) {
                    it = nxt;
                }
                consider(*it, a[i], ans_top, row);
            }
        }
        cout << row + 1 << " ";
        umap[seating[row]].erase(row);
        if(umap[seating[row]].empty()) {
            umap.erase(seating[row]);
        }
        seating[row]++;
        if(seating[row] < k)
            umap[seating[row]].insert(row);
    }
    cout << "\n";




    return 0;
}