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
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<int> l(k), r(k), interval(n + 1, 0);
    for(int i = 0; i < k; i++) {
        cin >> l[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> r[i];
    }

    for(int i = 0; i < k; i++) {
        for(int j = l[i]; j <= r[i]; j++) {
            interval[j] = i;
        }
    }
    
    vector<int> swapped(n + 2, 0);
    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        int ind = interval[x], start = min(x, l[ind] + r[ind] - x), end = max(x, l[ind] + r[ind] - x);
        swapped[start]++;
        swapped[end + 1]--;
    }
    string ans = "";
    for(int i = 1; i <= n; i++) {
        swapped[i] += swapped[i - 1];
        int ind = interval[i], opposite = l[ind] + r[ind] - i;
        if(swapped[i] & 1) {
            ans += s[opposite - 1];
        } else {
            ans += s[i - 1];
        }
    }
    cout << ans << "\n";
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
