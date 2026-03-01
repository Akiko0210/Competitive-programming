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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;
ll ans = 0;
const int N = 2e5;
vector<int> h(N), a(N), d(N), l(N), r(N);
unordered_map<ll, int> mx_ind_domain;

ll key(ll l, ll r) {
    return l * N + r;
}

ordered_set<int> count(int l, int r) {
    int pivot = mx_ind_domain[key(l, r)];
    ordered_set<int> lset = count(l, pivot - 1);
    ordered_set<int> rset = count(pivot + 1, r);
    rset.insert(d[pivot]);
}

void solve() {
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << "\n";
    // debug(n, k);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = max(h[i] - a[i], 0);
    }

    stack<int> inds;
    for(int i = 0; i < n; i++) {
        while(!inds.empty() && d[inds.top()] <= d[i]) {
            r[inds.top()] = i;
            inds.pop();
        }

        l[i] = (inds.empty() ? -1 : inds.top());
    }

    while(!inds.empty()) {
        r[inds.top()] = n;
        inds.pop();
    }

    for(int i = 0; i < n; i++) {
        mx_ind_domain[key(l[i], r[i])] = i;
    }

    // no we have the domains of each element. 
}

int main() {
    int t = 1;
    // cin >> t;
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

