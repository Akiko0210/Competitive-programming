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
    vector<int> a(n), pos(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int l = (n + 1) / 2, r = n / 2 + 1;
    int ans = n / 2;
    while (l > 0 && r <= n) {

        if(l == r) {
            l--, r++;
            continue;
        }
        if(pos[l] > pos[r] || pos[l + 1] < pos[l] || pos[r - 1] > pos[r]) {
            cout << ans << " \n";
            return;
        }
        ans--;
        l--, r++;
    }
    cout << ans << "\n";
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