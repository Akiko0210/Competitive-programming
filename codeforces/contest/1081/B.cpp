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
    int n, cnt1 = 0;
    string s;
    cin >> n >> s;
    // sum = even, n + 1 add.
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt1++;
        }
    }
    if(cnt1 % 2 == 0) {
        cout << cnt1 << "\n";
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        return;
    }
    if(cnt1 % 2 == 1 && n % 2 == 1) {
        cout << "-1\n";
        return;
    }

    cout << n - cnt1 << "\n";
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }





    /*
    1010
    1101
    0000

    0001
    do it on every 1 => 
    cnt1 - 1 = odd
    cnt1 -> even.

    if cnt1 = odd ? 
    if n = odd, odd + even != even;
    
    if n = even, cnt1 = odd, cnt0 = odd
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

