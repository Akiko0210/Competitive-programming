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
    vector<vector<int> > mat(n, vector<int>(3, 0));
    vector<vector<vector<int> > > sar(3, vector<vector<int> > (3));
    // i supply j demand;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        for(char c : s) {
            if(c == 'w') {
                mat[i][0]++;
            }
            if(c == 'i') {
                mat[i][1]++;
            }
            if(c == 'n') {
                mat[i][2]++;
            }
        }
        int supply;
        vector<int> demand;
        for(int j = 0; j < 3; j++) {
            if(mat[i][j] > 1) supply = j;
            if(mat[i][j] < 1) demand.pb(j);
        }
        for(int x : demand) {
            sar[supply][x].pb(i);
        }
    }

    vector<pair<pii, pii> > res;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) continue;
            while(sar[i][j].size() > 0 && sar[j][i].size() > 0) {
                int x = sar[i][j].back(), y = sar[j][i].back();
                sar[i][j].pop_back();
                sar[j][i].pop_back();
                res.pb({{x, y}, {i, j}});
            }
        }
    }

    while(sar[0][1].size() > 0 && sar[1][2].size() > 0 && sar[2][0].size() > 0) {
        int x = sar[0][1].back(), y = sar[1][2].back(), z = sar[2][0].back();
        sar[0][1].pop_back();
        sar[1][2].pop_back();
        sar[2][0].pop_back();
        res.pb({{x, y}, {0, 1}});
        res.pb({{y, z}, {0, 2}});
    }

    while(sar[0][2].size() > 0 && sar[1][0].size() > 0 && sar[2][1].size() > 0) {
        int x = sar[0][2].back(), y = sar[1][0].back(), z = sar[2][1].back();
        sar[0][2].pop_back();
        sar[1][0].pop_back();
        sar[2][1].pop_back();
        res.pb({{x, y}, {0, 1}});
        res.pb({{x, z}, {1, 2}});
    }

    char letter[] = {'w', 'i', 'n'};
    cout << res.size() << "\n";
    for(auto el : res) {
        cout << el.ff.ff + 1 << " "<< letter[el.ss.ff] << " " << el.ff.ss + 1 << " "  << letter[el.ss.ss] << "\n";
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
 