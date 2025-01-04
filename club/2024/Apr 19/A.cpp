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

/*
2 3 4 4 3 2
3 4 6 6 4 3
4 6 8 8 6 4 
4 6 8 8 6 4 
3 4 6 6 4 3
2 3 4 4 3 2
*/ 

void solve() {
    int x, y;
    cin >> x >> y;
    ll myLayer = max(x, y);
    ll baseLayer = myLayer - 1, base = baseLayer * baseLayer;
    if(myLayer & 1) {
        // left to right to top
        if(x == myLayer) {
            cout << base + y << "\n";
        } else {
            cout << (baseLayer + 1) * (baseLayer + 1) - x + 1 << "\n";
        }
    } else {
        if(y == myLayer) {
            cout << base + x << "\n";
        } else {
            cout << (baseLayer + 1) * (baseLayer + 1) - y + 1 << "\n";
        }
        // top to bottom to left
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

