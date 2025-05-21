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

bool s[10000];
vector<int> p;
void sieve() {
    for(int i = 2; i < 10000; i++) {
        if(!s[i]) {
            p.pb(i);
            for(int j = i * i; j < 10000; j += i) {
                s[j] = 1;
            }
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int x : p) {
            if(x > a[i]) break;
            int c = 0;
            while(a[i] % x == 0) {
                c++;
                a[i] /= x;
            }
            cnt[x] += c;
        }
        if(a[i] > 1) {
            cnt[a[i]]++;
        }
    }

    for(auto el : cnt) {
        if(el.ss % n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    sieve();
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
