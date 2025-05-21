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
    int n, mn = 1e9, mx= -1e9;
    cin >> n;
    vector<int> a(n);
    bool fnd = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if(a[i] != 0) {
            fnd = true;
        }
    }
    if(n == 1 || !fnd) {
        cout << "No\n";
        return;
    }
    


    sort(a.begin(), a.end());
    int l = 0, r = n - 1, sum = 0;

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(sum <= 0) {
            ans[i] = a[r];
            sum += a[r--];
        } else {
            ans[i] = a[l];
            sum += a[l++];
        }
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}

int main() {
    int t;
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
