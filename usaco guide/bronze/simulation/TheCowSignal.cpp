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
}

int main() {
    ifstream in ("cowsignal.in");
    ofstream out("cowsignal.out");
    int n, m, k;
    in >> n >> m >> k;
    vector<string> a(n);
    vector<vector<char> > ans(n * k, vector<char> (m * k, '.'));
    for(int i = 0; i < n; i++) {
        in >> a[i];
        for(int l = 0; l < m; l++) {
            for(int j = 0; j < k; j++) {
                for(int g = 0; g < k; g++) {
                    ans[i * k + j][l * k + g] = a[i][l];
                }
            }
        }
    } 
    for(auto row : ans) {
        for(auto c : row) {
            out << c;
        }
        out << "\n";
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

