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
    ll n;
    cin >> n;
    ll sum = (n * 2) * (n * 2 + 1) / 2;
    ll tsum = (n - 1) * n / 2;
    if((sum - tsum) % n) {
        cout << "NO\n";
        return;
    }
    ll x = (sum - tsum) / n;
    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        if(i < (n + 1) / 2)
            cout << i + 1 << " " << (n - i) * 2 << "\n"; 
        else 
            cout << i + 1 << " " << (2 * n - (i - (n + 1) / 2) * 2) - 1 << "\n";
    }

    /*
        ssum - ssum1 = sum;
        we have:
        1 2 3 ... 2n
        into
        x x+1 x+2 ... x+n-1
        1 6
        2 4
        3 5

        1 10 11
        2 8 10
        3 6 9
        4 9 13
        5 7 12
    */

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
