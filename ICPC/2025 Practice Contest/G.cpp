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
    int r, c;
    cin >> r >> c;
    vector<string> m(r);
    for(int i = 0; i < r; i++) {
        cin >> m[i];
    }

    int treasure = 0, row, col;
    for(int i = 1; i < r - 1; i++) {
        for(int j = 1; j < c - 1; j++) {
            if(m[i][j] == '0') {
                int cnt = 0;
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if(k == 0 && l == 0) continue;

                        if(m[i + k][j + l] == 'O') {
                            cnt++;
                        }
                    }
                }
                if(cnt == 8) {
                    treasure++;
                    row = i + 1;
                    col = j + 1;
                }
            }
        }
    }

    if(treasure == 1) {
        cout << row << " " << col << "\n";
    } else {
        cout << "Oh no!";
        if(treasure > 0) {
            cout << " " << treasure << " locations";
        }
        cout << "\n";
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

