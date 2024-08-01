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
/*
    on each column, we can calculate which row to flip if we want exactly and only i-th bit is set. 
        - first calculate which row to flip so that the column is all 0.
        - for i, flip the flip value.

    Now we want to know which column can get along. 
        - first we can compare the zero matrixes (flip array where i-th row becomes all 0.). 
        - if 2 zero matrix are same, we know that they can be special at once. (special bit at same location)
        - if they have only 1 bit different, they can't be special at once. 
        - if they have only 2 bit different, they can be special at once. (special bit at different location)
        - if they have 3 or more bit different, they can't be special at once. 

    Lets say we can combine the same zero matrixes. Then we only need to take care of matrixes with 2 different bits.
    If matrix A has set of matrixes that has 2 bits different, All the matrixes that has different bit at same position
    can get along.

    0011 -> 0  0 (0) 1
    0101 ->(1) 1  0  1
    1001 -> 1 (1) 0  1
    1111 -> 1  1  0  1

    Zero matrix is original matrix. 
    


*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > a(n, vector<bool> (m));
    vector<string> mat(n), trans(m);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
        for(int j = 0; j < m; j++) {
            a[i][j] = mat[i][j] - '0';
        }
    }

    for(int i = 0; i < m; i++) {
        trans[i] = "";
        for(int j = 0; j < n; j++) {
            trans[i] += mat[j][i];
        }
    }

    // lets first try with 1 hash.
    vector<ull> hashes(m, 0), cof(n);
    for(int i = 0; i < n; i++) {
        cof[i] = rng();
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j][i])
                hashes[i] = (hashes[i] ^ cof[j]);
        }
    }

    map<ull, int> mp;
    map<ull, pii> pos;
    for(int i = 0; i < m; i++) { //amin is the best
        for(int j = n - 1; j >= 0; j--) {
            mp[hashes[i] ^ cof[j]]++;
            pos[hashes[i] ^ cof[j]] = {i, j};
        }
    }

    ull ans = 0, mxhash = 0;
    for(auto &[k, v] : mp) {
        if(v > ans) {
            ans = v;
            mxhash = k;
        }
    }
    // debug(pos[mxhash].first, pos[mxhash].second);
    string res = trans[pos[mxhash].first];
    res[pos[mxhash].second] = res[pos[mxhash].second] == '1' ? '0' : '1';

    cout << ans << "\n" << res << "\n";



}

int main() {
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

