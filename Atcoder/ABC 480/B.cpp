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
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    for(string &s : names) cin >> s;

    vector<int> votes(n, 0);

    auto calc = [&](string ballot) {
        int pos = -1, poscnt = 0;
        for(int j = 0; j < n; j++) {
            if(ballot.size() != names[j].size()) continue;

            int dif = 0;
            for(int i = 0; i < ballot.size(); i++) {
                if(ballot[i] != names[j][i]) {
                    dif++;
                }
            }

            if(dif == 0) {
                votes[j]++;
                return;
            }
            if(dif == 1) {
               pos = j;
               poscnt++;
            }
        }

        if(poscnt == 1) {
            votes[pos]++;
        }
    };

    for(int i = 0; i < m; i++) {
        string ballot;
        cin >> ballot;
        calc(ballot);
    }

    for(int i = 0; i < n; i++) cout << votes[i] << "\n";
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

