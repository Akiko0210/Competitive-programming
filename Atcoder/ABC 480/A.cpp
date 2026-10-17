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
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<int> ind(4);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ind[s[i][j] - 'A'] = i * 2 + j;
        }
    }

    int A = ind[0], D = ind[3];
    if(A > D) swap(A, D);

    if(A == 0 && D == 3 || A == 1 && D == 2) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

