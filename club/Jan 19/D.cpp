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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int h[2], w[2];
        h[0] = w[0] = -1000;
        h[1] = w[1] = 1000;
        for(int i = 0; i < 4; i++) {
            int x, y;
            cin >> x >> y;
            h[0] = max(h[0], y);
            w[0] = max(w[0], x);
            h[1] = min(h[1], y);
            w[1] = min(w[1], x);
        }
        cout << (h[0] - h[1]) * (w[0] - w[1]) << "\n";
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

