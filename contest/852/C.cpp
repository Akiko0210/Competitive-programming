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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    int l1 = 0, r1 = n - 1;

    while(l1 < r1) {
        if(a[l1] == l) {
            l1++;
            l++;
            continue;
        }
        if(a[l1] == r) {
            l1++;
            r--;
            continue;
        }
        if(a[r1] == l) {
            r1--;
            l++;
            continue;
        }
        if(a[r1] == r) {
            r1--;
            r--;
            continue;
        }
        break;
    }
   
    if(l1 >= r1) {
        cout << "-1\n";
    } else {
        cout << l1 + 1 << " " << r1 + 1 << "\n";
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
