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
    int n, x1 = 0, x2 = 0, y1 = 0, y2 = 0, sum = 0;
    cin >> n;
    for(int i = 1; n > 0; i++) {
        int dc = min(i, n);
        if(i % 4 > 1) {
            // player 2
            if(sum & 1) {
                // starts with white
                x2 += (dc + 1) / 2;
                y2 += dc / 2;
            } else {
                // starts with black
                x2 += dc / 2;
                y2 += (dc + 1) / 2;
            }
        } else {
            if(sum & 1) {
                // starts with white
                x1 += (dc + 1) / 2;
                y1 += dc / 2;
            } else {
                // starts with black
                x1 += dc / 2;
                y1 += (dc + 1) / 2;
            }
        }
        sum += dc;
        n -= dc;
    }
    cout << y1 << " " << x1 << " " << y2 << " " << x2 << "\n";
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
