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

int main() {
    /*
    20 = 2^2 * 5
    3 * 2 = 6

    64000000 = 2^12 * 5^6

    if n is prime, x = n^2
    if n is prime square, x = n^3
    otherwise, x is n^4 or more. 
    */
    ll x;
    cin >> x;

    for(int i = 1; i <= 40000; i++) {
        int cnt = 0;
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                cnt++;
                if(i / j != j) cnt++;
            }
        }
        ll temp = x;
        while(cnt > 0 && temp % i == 0) {
            cnt--;
            temp /= i;
        }

        if(cnt == 0 && temp == 1) {
            cout << i << "\n";
            return 0;
        }
    }

    ll y = cbrt(x);
    // y must be prime^2
    if(y * y * y == x) {
        // 
        int p = sqrt(y);
        if(p * p == y) {
            bool isprime = true;
            for(int i = 2; i * i <= p; i++) {
                if(p % i == 0) {
                    isprime = false;
                    break;
                }
            }
            if(isprime) {
                cout << y << "\n";
                return 0;
            }
        }
    }

    y = sqrt(x);
    if(y * y == x) {
        bool isprime = true;
        for(int i = 2; i * i <= y; i++) {
            if(y % i == 0) {
                isprime = false;
                break;
            }
        }
        if(isprime) {
            cout << y << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

