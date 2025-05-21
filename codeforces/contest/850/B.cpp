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
    // calculate max shift
    int n, h, w;
    cin >> n >> w >> h;
    vector<pii> a(n), b(n);
    
    for(auto &el : a) {
        int x;
        cin >> x;
        el.ff = x - w;
        el.ss = x + w;
    } 
    for(auto &el : b) {
        int x;
        cin >> x;
        el.ff = x - h;
        el.ss = x + h;
    } 

    int shift = b[0].ff - a[0].ff, dif = w * 2 - h * 2; // left shift
    for(int i = 1; i < n; i++) {
        a[i].ff += shift;
        a[i].ss += shift;

        if(a[i].ff <= b[i].ff) {
            if(a[i].ss < b[i].ss) {
                cout << "NO\n";
                return;
            } else {
                dif = min(dif, a[i].ss - b[i].ss);
            }
        } else {
            int temp = min(a[i].ff - b[i].ff, dif);
            dif -= temp;
            shift -= temp;
            a[i].ff -= temp;
            a[i].ss -= temp;
            if(a[i].ff > b[i].ff) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
 
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
