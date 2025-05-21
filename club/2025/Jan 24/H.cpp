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
    ll n;
    cin >> n;
    if(n < 3) {
        cout << "-1\n";
        return;
    }

    if(n & 1) {
        cout << "2\n";
        return;
    }

    
    /*
    k different. 
    k * (k - 1) / 2
    n = k * (k - 1) / 2 + k * x
    n = k * (k - 1) / 2 + k * x


    n >= 3

    n is odd, 2x + 1 at least 3
    k = 2, 1, 2x works. 
    
    n is 3x
    k = 3, 1 2 3, at least 6 
    
    n is 4x
    k = 4, 1 2 3 4, = 10 

    if n has odd divisor, k, and more than k * (k + 1) / 2, it's instant k. 

    3 5 7 9 11 ... 
     4 
       6  9   12  ....
         8
           10     14     18 ....
                13

                     15      20      25 ....
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

