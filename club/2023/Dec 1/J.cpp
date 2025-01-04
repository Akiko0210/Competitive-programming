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

int main() {

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    FAST

    int t = 1;
    cin >> t;
    while(t--) {
        int n, sx, sy;
        cin >> n >> sx >> sy;
        vector<set<int> > a(2);
        vector<pii> pos(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> pos[i].ff >> pos[i].ss;
            pos[i].ff &= 1;
            pos[i].ss &= 1;
            a[(pos[i].ff + pos[i].ss) % 2].insert(i);
        }

        int w = (sx + sy) % 2, x;
        if(a[w].size() >= a[w ^ 1].size()) {
            cout << "First" << endl;
            for(int i = 0; i < n; i++) {
                if(i & 1) {
                    cin >> x;
                    a[(pos[x].ff + pos[x].ss) % 2].erase(x);
                } else {
                    int p = a[w ^ 1].empty() ? w : (w ^ 1);
                    cout << *a[p].begin() << endl;
                    a[p].erase(a[p].begin());
                }
            }
        } else {
            cout << "Second" << endl;
            int x;
            cin >> x;
            a[(pos[x].ff + pos[x].ss) % 2].erase(x);
            for(int i = 0; i < n - 1; i++) {
                if(i & 1) {
                    cin >> x;
                    a[(pos[x].ff + pos[x].ss) % 2].erase(x);
                } else {
                    int p = a[w].empty() ? (w ^ 1) : w;
                    cout << *a[p].begin() << endl;
                    a[p].erase(a[p].begin());
                }
            }
        }
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

