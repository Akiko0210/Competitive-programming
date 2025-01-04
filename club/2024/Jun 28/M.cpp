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
    string s, t;
    cin >> s >> t;
    /*
    s -> t
    11 -> 10, 01
    10, 01 -> 11
    00 -> 00

    we can move a bit to anywhere. we can remove any bit, we can spawn a bit. 
    no condition: size different, one is all 0s and other is not.
    */

    if((int)s.size() != (int)t.size()) {
        cout << "NO\n";
        return 0;
    }

    bool ahasbit = false, bhasbit = false;
    for(char c : s) {
        ahasbit |= (c == '1');
    }

    for(char c : t) {
        bhasbit |= (c == '1');
    }

    cout << ((ahasbit ^ bhasbit) ? "NO\n" : "YES\n");



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

