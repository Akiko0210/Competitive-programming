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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(a.begin(), a.end());

    if(m > n / 2) {
        cout << "-1\n";
        return;
    }
    vector<pii> ans;
    auto push = [&](int i, int j) {
        ans.pb({a[i - 1].ss, a[j - 1].ss});
    };
    auto terminate = [&] (int x) {
        for(int i = 1; i < x; i++) {
            push(i + 1, i);
        }
    };
    if(m > 0) {
        int del = n - m * 2;
        terminate(del + 1);
        for(int i = del + 1; i < n; i += 2) {
            push(i + 1, i);
        }
    } else {
        int i = n - 2;
        while(i >= 0 && a[n - 1].ff > 0) {
            a[n - 1].ff -= a[i].ff;
            i--;
        }
        if(a[n - 1].ff > 0) {
            cout << "-1\n";
            return;
        }
        terminate(i + 2);
        push(n, i + 2);

        for(int j = i + 3; j < n; j++) {
            push(j, n);
        }
    }

    cout << ans.size() << "\n";
    for(pii op : ans) {
        cout << op.ff << ' ' << op.ss << "\n";
    }
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

