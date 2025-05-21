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
    int n;
    cin >> n;
    vector<int> cnt(20);
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 0; j < 20; j++) {
            if(i & (1 << j)) {
                cnt[j]++;
            }
        }
    }

    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
        if(i > 0) a[i] ^= a[i - 1];
    }

    int x = 0;
    for (int i = 0; i < 20; i++) {
        int cur = 0;
        for(int j = 0; j < n - 1; j++) {
            if(a[j] & (1 << i)) {
                cur++;
            }
        }
        if(cnt[i] != cur) {
            x += (1 << i);
        }
    }

    cout << x << " ";
    for(int i = 0; i < n - 1; i++) {
        cout << (x ^ a[i]) << " ";
    }
    cout << "\n";



    /*
    array b such that:
    0 - (n - 1) appear exactly once,
    b[i] ^ b[i + 1] = a[i]
    b[i - 1] ^ b[i + 1] = a[i] ^ a[i - 1];
    b[i - 2] ^ b[i + 1] = a[i] ^ a[i - 1] ^ a[i - 2];

    4
    2 1 2
    10
    01
    10
    0 2 3 1


    6
    1 6 1 4 1
    001
    110
    001
    100
    001
    1 7 6 2 3

    000
    001
    010
    011
    100
    101

    b[0] = 010
    001 ^ b[0] = b[1]
    111 ^ b[0] = b[2]
    110 ^ b[0] = b[3]
    010 ^ b[0] = b[4]
    011 ^ b[0] = b[5]
    2 3 5 4 0 1

    */
}

int main() {
    int t = 1;
    // cin >> t;
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

