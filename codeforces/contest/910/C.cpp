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
    n--, m--;
    if(n + m > k || (k - n - m) % 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    bool cnt = 0;
    for(int j = 0; j < m; j++) {
        if(cnt) {
            cout << "B ";
        } else {
            cout << "R ";
        }
        cnt ^= 1;
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cnt) {
                cout << "R ";
            } else {
                cout << "B ";
            }
        }
        cout << "\n";
    }

    int cnt1 = cnt;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cnt1) {
                cout << "B ";
            } else {
                cout << "R ";
            }
        }
        if(cnt) {
            cout << "B ";
        } else {
            cout << "R ";
        }
        cnt ^= 1;
        cout << "\n";
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

