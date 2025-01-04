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
    /*
    a[gcd(i, j)] != gcd(a[i], a[j]);
    a = lexograpically max
    a chosen from S

    when it's -1?
    Guess1: 
    when m = 1 and n > 1


    m = 2 uyd n >= 4 uyd -1
    m = 3 uyd n >= 6 uyd -1

     1 2 3 4 5 6
   1 x
   2 1 x
   3 1 1 x
   4 1 2 1 x
   5 1 1 1 1 x
   6 1 2 3 2 1 x
   -> gcd(a[2], a[4]) != a[2] -> a[2] ni a[4] g huwaahgui
   -> gcd(a[3], a[6]) != a[3] -> a[3] ni a[6] g huwaahgui
   -> gcd(a[2], a[6]) != a[2] -> a[2] ni a[6] g huwaahgui
   -> a[1] ni uur ymar ch toog huwaahgui.

    */
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), level(n + 1, 1);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i * 2; j <= n; j += i) {
            level[j] = max(level[j], level[i] + 1);
        }
    }


    int mxlevel = *max_element(level.begin(), level.end());

    if(mxlevel > m) {
        cout << "-1\n";
        return;
    }

    reverse(b.begin(), b.end());
    for(int i = 0; i < n; i++) {
        a[i] = b[level[i + 1] - 1];
    }

    for(int x : a) {
        cout << x << " ";
    }
    cout << "\n";



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

