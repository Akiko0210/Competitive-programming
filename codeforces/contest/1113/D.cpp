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
    int n, q;
    string s, t;
    cin >> n >> q >> s >> t;
    vector<int> sum1(n, 0), sum2(n, 0), matching1(n, 0), matching0(n, 0);
    for(int i = 0; i < n; i++) {
        sum1[i] = s[i] - '0';
        sum2[i] = t[i] - '0';
        if(s[i] == '1' && t[i] == '1') {
            matching1[i] = 1;
        }
        if(s[i] == '0' && t[i] == '0') {
            matching0[i] = 1;
        }
        if(i > 0) {
            sum1[i] += sum1[i - 1];
            sum2[i] += sum2[i - 1];
            matching0[i] += matching0[i - 1];
            matching1[i] += matching1[i - 1];
        }
    }
    
    /*
    001
    110 -> no
    00011
    01111 -> yes

    01010
    10101
    */
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int len = r - l + 1;
        int m0 = matching0[r] - (l > 0 ? matching0[l - 1] : 0);
        int m1 = matching1[r] - (l > 0 ? matching1[l - 1] : 0);
        int c11 = sum1[r] - (l > 0 ? sum1[l - 1] : 0);
        int c21 = sum2[r] - (l > 0 ? sum2[l - 1] : 0);
        int c10 = len - c11;
        int c20 = len - c21;

        if((c11 * 2 >= len && c21 >= len) || (c10 * 2 >= len && c20 * 2 >= len)) {
            cout << "YES\n";
            continue;
        }

        if(c11 > c21) {
            swap(c11, c21);
            swap(c10, c20);
        }
        int k = min(m1 * 2, c21), q = min(m0 * 2, c10);
        if(((c21 - k) * 2 <= len - k) || ((c10 - q) * 2 <= len - q)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
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

