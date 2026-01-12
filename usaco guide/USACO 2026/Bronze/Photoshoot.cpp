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

int main() {
    int n, k, q, mx = 0;
    cin >> n >> k >> q;
    vector<vector<int> > mat(n, vector<int> (n, 0));

    while(q--) {
        int row, c, v;
        cin >> row >> c >> v;
        row--;
        c--;
        mat[row][c] = v;
        int t = max(row - k + 1, 0), b = min(row + k - 1, n - 1), l = max(c - k + 1, 0), r = min(c + k - 1, n - 1);
        vector<vector<int> > temp(b - t + 2, vector<int> (r - l + 2, 0));
        for(int i = t; i <= b; i++) {
            for(int j = l; j <= r; j++) {
                temp[i - t + 1][j - l + 1] = mat[i][j];
            }
        }

        for(int i = 1; i < b - t + 2; i++) {
            for(int j = 1; j < r - l + 2; j++) {
                temp[i][j] += temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1];
            }
        }

        for(int i = k; i < b - t + 2; i++) {
            for(int j = k; j < r - l + 2; j++) {
                int sum = temp[i][j] - temp[i - k][j] - temp[i][j - k] + temp[i - k][j - k];
                mx = max(mx, sum);
            }
        }
        cout << mx << "\n";
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

