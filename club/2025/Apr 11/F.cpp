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
    8
    4 - A
    2 - B
    1 - A
    1 - B

    B = 3
    A = 5

    1 - A
    1 - B
    3 - A
    1 - B
    1 - A
    1 - B

    when (2k + 1) * 2 -> take 2k + 1
    when (2k) * 2 -> take 1


    n = 16
    1)
    8 - A
    4 - B
    2 - A
    1 - B
    1 - A

    B = 5
    A = 11

    2)
    1 - A (15)
    1 - B (14)
    7 - A (7)
    1 - B (6)
    3 - A (3)
    1 - B (2)
    1 - A (1)
    1 - B (1)

    4 - 12

    n = 5
    1 - A
    1 - B
    1 - A
    1 - B
    1 - A
    
    
    */

    ll n;
    cin >> n;
    vector<ll> p(2, 0);
    int ind = 0;

    while(n) {
        if(n & 1) {
            n--;
            p[ind]++;
        } else {
            if(n % 4 == 2) {
                n /= 2;
                p[ind] += n;
            } else {
                if(n > 4) {
                    n--;
                    p[ind]++;
                } else {
                    n /= 2;
                    p[ind] += n;
                }
            }
        }
        ind = 1 - ind;
    }

    cout << p[0] << "\n";
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

