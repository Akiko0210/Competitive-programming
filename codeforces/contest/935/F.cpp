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

const ll MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(m), f(k);
    for(int &x : a) cin >> x;
    for(int &x : d) cin >> x;
    for(int &x : f) cin >> x;

    sort(d.begin(), d.end());
    sort(f.begin(), f.end());


    auto run = [&] (int pivot) {
        int ans, dif = INF;
        int r = k - 1;
        for(int i = 0; i < m; i++) {
            while(r >= 0 && f[r] + d[i] > pivot) {
                r--;
            }
            if(r < 0) r++;
            if(dif > abs(pivot - f[r] - d[i])) {
                // debug(pivot - f[r] - d[i], dif);
                dif = abs(pivot - f[r] - d[i]);
                ans = f[r] + d[i];
            }
            if(r < k - 1 && dif > (f[r + 1] + d[i] - pivot)) {
                // debug(f[r + 1] + d[i] - pivot, dif);
                dif = f[r + 1] + d[i] - pivot;
                ans = f[r + 1] + d[i];
            }
        }
        // debug(ans, pivot, dif);
        return ans;
    };

    if(n == 1) {
        cout << abs(a[0] - run(a[0])) << "\n";
        return;
    }

    int maxdis = 0;
    pii range;
    vector<int> distances;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] > maxdis) {
            range = {a[i], a[i - 1]};
            // pivot = (a[i] + a[i - 1]) / 2;
            maxdis = a[i] - a[i - 1];
        }
        distances.pb(a[i] - a[i - 1]);
    }

    sort(distances.rbegin(), distances.rend());
    if(distances[0] == distances[1]) {
        cout << distances[0] << "\n";
        return;
    }

    // debug(pivot);
    // now our new problem has to fit into range  
    // debug(range.ff, range.ss);
    if(distances.size() == 1) {
        int num = run((range.ff + range.ss) / 2);
        // debug()
        cout << min(max(range.ff - num, num - range.ss), distances[0]) << "\n";
        return;
    }
    int num = run((range.ff + range.ss) / 2);
    cout << max(min(max(range.ff - num, num - range.ss), distances[0]), distances[1]) << "\n";
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

