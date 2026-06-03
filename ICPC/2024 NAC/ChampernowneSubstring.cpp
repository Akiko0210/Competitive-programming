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

const ll MOD = 998244353;

ll pw(ll a, ll b) {
    if(b == 0) return 1;
    ll h = pw(a, b / 2);
    h = h * h % MOD;

    if(b & 1) {
        h = h * a % MOD;
    }
    return h;
}

ll within(int len, string& s) {
    /*
    return first digit position within len lenght numbers. 
    depends on s.length()
    
    */

    // int l = s.size();
    ll roff;
    string cur(len, '9');
    if(len == 1) {
        roff = 9;
        cur[0] = '1';
    } else {
        /*
        25 numbers before. 
        75, 76, 77, 78, ..., 99 -> 25 numbers
        10^len - start.
        */ 
        roff = 25;
        cur[len - 2] = '7';
        cur[len - 1] = '5';
    }
    /*
    prev = len * (9 * 10 ^ (len - 1) - roff);
    */ 
    ll prev = (ll)len * ((9 * pw(10, len - 1) % MOD - roff + MOD) % MOD) % MOD;

    // build the string. 
    string t = cur;
    for(int i = 1; i < roff; i++) {
        if(cur[len - 1] == '9') {
            cur[len - 1] = '0';
            cur[len - 2]++;
        } else {
            cur[len - 1]++;
        }
        t += cur;
    }

    cur = string(len + 1, '0');
    cur[0] = '1';
    t += cur;
    for(int i = 1; i < 25; i++) {
        if(cur[len] == '9') {
            cur[len] = '0';
            cur[len - 1]++;
        } else {
            cur[len]++;
        }
        t += cur;
    }

    debug(t);
    // check substring.

    for(int i = 0; i + s.size() <= t.size(); i++) {
        bool match = false;
        // for(
    }

}

ll inbetween(int len, string& s) {
    /*
    first pos in between len and len + 1 long numbers.

    */


}

ll totalChar(int len) {
    ll pw = 1, ans = 0;
    while(pw <= len) {
        (ans += pw * 9) %= MOD;
        (pw *= 10) %= MOD;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;

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

