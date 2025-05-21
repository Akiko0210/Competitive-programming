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
    int n;
    cin >> n;

    vector<int> a(n), test(n + 1, -1), last(n + 1, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    test[n] = 0;

    for(int i = n - 1; i >= 0; i--) {
        int len = n - 1 - i;
        int nxt = i + a[i] + 1;
        if(nxt <= n && test[nxt] >= 0) {
            test[i] = test[nxt] + 1;
        }
    }

    for(int i = 0; i <= n; i++) {
        if(test[i] >= 0) {
            last[test[i]] = i;
        }
    }

    vector<bool> byOne(n + 1, 0);

    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == test[i + 1]) {
            cout << "0\n";
            continue;
        }

        if(test[i + 1] >= 0) {
            byOne[i] = 1;
            cout << "1\n";
            continue;
        }

        int nxt = i + 1 + a[i + 1] + 1;
        if(byOne[nxt - 1]) {
            byOne[i] = 1;
            cout << "1\n";
            return;
        } 

        
    }
}

int main() {
    FAST
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
