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
    vector<int> ans;
    while((n & 1) && n > 1) {
        if(((n + 1) / 2) % 2) {
            ans.pb(1);
            n = (n + 1) / 2;
        } else {
            ans.pb(2);
            n = (n - 1) / 2;
        }
        
    }
    if(n % 2 == 0 || ans.size() > 40) {
        cout << "-1\n";
    } else {
        cout << ans.size() << "\n";
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
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
