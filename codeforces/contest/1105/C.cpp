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
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    if(n == 1) {
        cout << "0\n";
        return;
    }
    
    if(x == 0) {
        cout << "1\n";
        return;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= (x ^ a[i])) {
            ans++;
        }
    }
    cout << ans << "\n";


//  5
//  1 4 5 2 6
//  out: 3
/*
    What's Alice's winning condition? 
    What's the losing condition of a player? 
        Can't choose an array b. st b[i] <= a[i] and XOR(b) = 0.
        b can be always = {0, 0, 0, 0, ... 0, 1, 1}
        -> Leave only 1 number positive.

    We need to count Alice's winning first move. 
    1 2 4 5 6
    1 2 4 5 2 -> winning
    1 2 4 1 6 -> winning
    1 2 0 5 6 -> winning
    
    b[i] can be 0 but SUM(b) > 0
*/
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

