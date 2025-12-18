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
const int N = 225;

vector<vector<int> > mult(vector<vector<int> >& a, vector<vector<int> >& b) {
    int n = a.size(), m = a[0].size(), r = b[0].size();
    vector<vector<int> > ans(n, vector<int> (r, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            for(int k = 0; k < m; k++) {
                (ans[i][j] += (ll)a[i][k] * b[k][j] % MOD) %= MOD;
            }
        }
    }
    return ans;
}

vector<vector<int> > pw(vector<vector<int> >& a, ll m) {
    if(m == 1) {
        return a;
    }
    vector<vector<int> > half = pw(a, m / 2);
    half = mult(half, half);
    if(m & 1) {
        half = mult(half, a);
    }
    return half;
}

int main() {
    ll a, b;
    cin >> a >> b;
    /*
    dp[i][r] = sum (dp[j][r - i] for j in [0 ... 9] that j != i)
    N = b(mod 9) and N = b(mod 25)
    */

    if(a < 4) {
        int start = 1, ans = 0;
        for(int i = 1; i < a; i++) {
            start *= 10;
        }
        for(int i = start; i < start * 10; i++) {
            if(i % N == b)  {
                bool isvalid = true;
                int temp = i;
                while(temp > 10) {
                    if(temp % 10 == (temp / 10 % 10)) {
                        isvalid = false;
                        break;
                    }
                    temp /= 10;
                }
                if(isvalid) debug(i);
                ans += isvalid;
            }
        }
        cout << ans << "\n";
        return 0;
    }

    vector<vector<int> > mat(90, vector<int> (90, 0));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 9; j++) {
            for(int k = 0; k < 10; k++) {
                if(k != i) {
                    int rem = (j + k) % 9;
                    mat[j * 10 + i][rem * 10 + k] = 1;
                }
            }
        }
    }
    vector<vector<int> > init(1, vector<int> (90, 0));
    for(int i = 1; i < 10; i++) {
        init[0][(i % 9) * 10 + i] = 1;
    }
    mat = pw(mat, a - 3);
    // for(int i = 0; i < 90; i++) {
    //     for(int j = 0; j < 90; j++) {
    //         if(mat[i][j] > 0) {
    //             debug(i / 10, i % 10, j / 10, j % 10);
    //         }
    //     }
    // }
    init = mult(init, mat);
    int ans = 0;
    for(int x = 0; x < 100; x++) {
        if((x % 25 != b % 25) || (x % 10 == x / 10)) continue;

        int dsum = x % 10 + x / 10, desired_rem = (b % 9 - dsum % 9 + 9) % 9;
        int temp = 0;
        // debug(x, desired_rem);
        for(int i = 0; i < 10; i++) {
            if(x / 10 == i) continue;
            (temp += init[0][desired_rem * 10 + i]) %= MOD;
            // debug(desired_rem, i, init[0][desired_rem * 10 + i]);
        }
        (ans += temp) %= MOD;
        // debug(temp, x);
    }
    cout << ans << "\n";
    // mat ^ a - 3
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

