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

vector<int> last(50001, -1);

void solve() {
    int m;
    cin >> m;
    vector<int> n(m);
    vector<vector<int> > a(m);
    for(int i = 0; i < m; i++) {
        cin >> n[i];
        a[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            last[a[i][j]] = i;
        }
    }

    vector<int> ans(m);

    for(int i = 0; i < m; i++) {
        bool fnd = false;
        for(int j = 0; j < n[i]; j++) {
            if(last[a[i][j]] == i) {
                ans[i] = a[i][j];
                fnd = true;
                break;
            }
        }
        if(!fnd) {
            cout << "-1\n";
            return;
        }
    }

    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n[i]; j++) {
            last[a[i][j]] = -1;
        }
    }
}

int main() {
    int t;
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
