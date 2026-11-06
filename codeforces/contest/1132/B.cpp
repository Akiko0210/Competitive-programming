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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    /*
        in sorted order, it's always n.

        1 2 3 10 9 10 -> 6
        we need exactly k.
        k = 2
        10 10 1 2 3 9
        k = 1 -> NO
        1 2 3 9 9 10
        k = 2
        10 9 1 2 3 9

        if max element appears more than k times -> no

    */

    sort(a.begin(), a.end());
    vector<int> ans(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(i < k) {
            ans[i] = a[n - k + i];
        } else {
            int j = i - k;
            ans[i] = a[n - k - 1 - j];
        }

        cnt += (a[n - 1 - i] == a[n - 1]);
    }
    if(cnt > k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int x : ans) {
            cout << x << " ";
        }
        cout << "\n"; 
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

