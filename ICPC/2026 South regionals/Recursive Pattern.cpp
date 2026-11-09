#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
#define MAT vector<vector<bool> >
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

vector<MAT> simplePatterns;

pair<MAT, MAT> add_padding(MAT& init, MAT& universal) {
    int n = init.size(), m = init[0].size();
    MAT mat(n + 2, vector<bool> (m + 2, 0));
    MAT newuniversal(n + 2, vector<bool> (m + 2, 1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i + 1][j + 1] = init[i][j];
            newuniversal[i + 1][j + 1] = universal[i][j];
        }
    }
    return {mat, newuniversal};
}

bool match(MAT& mat, MAT& universal, int top, int left, int ind) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(universal[top + i][left + j] || (mat[top + i][left + j] == simplePatterns[ind][i][j])) {
                continue;
            }

            return false;
        }
    }
    return true;
}

bool canDivide(MAT& mat, MAT& universal, int startx, int starty, int ind) {
    int n = mat.size(), m = mat[0].size();
    
    for(int i = startx; i + 1 < n; i += 2) {
        for(int j = starty; j + 1 < m; j += 2) {
            if(match(mat, universal, i, j, ind) || match(mat, universal, i, j, 0)) {
                continue;
            }
            return false;
        }
    }
    return true;
}

pair<MAT, MAT> divide(MAT& mat, MAT& universal, int startx, int starty, int ind) {
    int n = mat.size(), m = mat[0].size();
    int newn = (n - startx) / 2, newm = (m - starty) / 2;
    MAT ans(newn, vector<bool> (newm, 0));
    MAT newuniversal(newn, vector<bool> (newm, 0));
    for(int i = startx; i + 1 < n; i += 2) {
        for(int j = starty; j + 1 < m; j += 2) {
            int x = (i - startx) / 2, y = (j - starty) / 2;
            if(match(mat, universal, i, j, ind)) {
                if(match(mat, universal, i, j, 0)) {
                    newuniversal[x][y] = 1; // universal key;
                    continue;
                }

                ans[x][y] = 1;
                continue;
            }
            ans[x][y] = 0;
        }
    }
    return {ans, newuniversal};
}

unordered_set<string> impossible;

bool check(MAT& mat, MAT& universal) {
    int xcnt = 0, n = mat.size(), m = mat[0].size();
    for(auto &row : mat) {
        for(bool c : row) {
            xcnt += c;
        }
    }

    if(xcnt == 0 || xcnt == n * m || (n <= 2 && m <= 2)) {
        return true;
    }

    // Encode the dimensions and all three cell types.
    string key = to_string(n) + "," + to_string(m) + ":";
    key.reserve(key.size() + size_t(n) * m);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            key.push_back(
                universal[r][c] ? '?' :
                mat[r][c] ? 'X' : 'o'
            );
        }
    }

    // We already searched this exact state and found no solution.
    if (impossible.count(key)) {
        return false;
    }

    auto [padded, puniversal] = add_padding(mat, universal);

    for(int i = 1; i < 16; i++) {
        for(int startx = 0; startx < (n == 1 ? 1 : 2); startx++) {
            for(int starty = 0; starty < (m == 1 ? 1 : 2); starty++) {
                if(canDivide(padded, puniversal, startx, starty, i)) {
                    auto [nxtmat, newuniversal] = divide(padded, puniversal, startx, starty, i);
                    if(check(nxtmat, newuniversal)) {
                        return true;
                    }
                }
            }
        }
    }

    impossible.insert(std::move(key));

    return false;
}

int main() {
    FAST
    // . = universal match
    // X
    // o

    for(int i = 0; i < 16; i++) {
        vector<vector<bool> > basic(2, vector<bool> (2));
        for(int r = 0; r < 2; r++) {
            for(int c = 0; c < 2; c++) {
                int cur = r * 2 + c;
                if(i & (1 << cur)) {
                    basic[r][c] = 1;
                } else {
                    basic[r][c] = 0;
                }
            }
        }
        simplePatterns.push_back(basic);
    }

    int n, m;
    cin >> n >> m;
    MAT mat(n, vector<bool> (m, 0));
    MAT universal = mat;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            mat[i][j] = (s[j] == 'X');
        }
    }

    cout << check(mat, universal) << "\n";





    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

