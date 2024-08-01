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
    cin >> n >> s >> t >> q;
    vector<bool> a(n), b(n);
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }
    
    
    vector<bool> a1(n), b1(n);
    a1[0] = b1[0] = a[0];
    a1[n - 1] = b1[n - 1] = a[n - 1];
    for(int i = 1; i < n - 1; i++) {
        a1[i] = b[i] | (!a[i - 1] & !a[i + 1]);
    }

    for(int i = 1; i < n - 1; i++) {
        b1[i] = a[i] | (a1[i - 1] & a1[i + 1]);
    }

    vector<int> sum(n, 0);
    sum[0] = b1[0];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + b1[i];
    }

    auto calc = [&] (int l, int r) -> int {
        int len = r - l + 1, cnt = 0;
        if(len == 1) return a[l];
        if(len == 2) return (int)a[l] + a[r];
        if(len == 3) return (int)a[l] + a[r] + (a[l + 1] | (b[l] & b[r]));

        cnt = (int)a[l] + a[r] + (a[l + 1] | (b[l] & a1[l + 2])) + (a[r - 1] | (b[r] & a1[r - 2]));
        cnt += sum[r - 2] - sum[l + 1];
        return cnt;
    };

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << calc(l, r) << "\n";
    }

}

int main() {
    FAST
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

