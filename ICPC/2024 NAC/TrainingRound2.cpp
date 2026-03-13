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
const int N = 5005;

int main() {
    FAST
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> al(n), ar(n), bl(n), br(n);
    for(int i = 0; i < n; i++) {
        cin >> al[i] >> ar[i] >> bl[i] >> br[i];
        al[i] -= x;
        ar[i] -= x;
        bl[i] -= y;
        br[i] -= y;
    }

    bitset<N> dp[N];
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        int r = min(br[i], n), l = max(bl[i], 0);
        // debug(i, l, r);
        if(r < l) continue;

        for(int j = min(ar[i], n); j >= max(al[i], 0); j--) {
            // j in range
            // find the overlapping b range. -> [l, r]
            int up = N - 1 - r;
            bitset<N> pos = (((dp[j] << up) >> (up + l)) << l);
            dp[j] |= (pos << 1);
            dp[j + 1] |= pos;
        }

        // for(int j = 0; j <= 20; j++) {
        //     for(int k = 0; k <= 20; k++) {
        //         cout << dp[j][k];
        //     }
        //     cout << "\n";
        // }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j]) {
                // debug(i, j);
                ans = max(ans, i + j);
            }
        }
    }
    cout << ans << "\n";
    

    /*
    -1 1 4
    1  2 3
    2  

    -1 1 2
    1  2
    4  3

    
    ? 
    [(0, 0), (0, 0)], 
    [(0, 0), (1, 1)],
    [(1, 1), (1, 1)], 
    [(1, 1), (0, 0)]


    after solving each problem, x++ or y++.
    Can solve problem i only if 
    al[i] <= x <= ar[i]
    bl[i] <= y <= br[i]
    
    n <= 5000

    dp[i][A][B] = at i, when implementation skill is increased by A
    and thinking skill increased by B, what's the max problems 
    she can solve? -> stupid because A + B = number of problems solved.
    at i, maximize A + B sum. So it's greedy problem.
    dp[i][A] = max B.
    
    Think towards direction that maybe it's not greedy.
    dp[A][B] is min ind that can reach A, B after. 
    
    dp[A][B] -> 
    1. find ind in range(dp[A][B] + 1, n - 1).
    al[ind] <= A <= ar[ind] && bl[ind] <= B <= br[ind]
    2. dp[A + 1][B] = min(dp[A + 1][B], ind)
    3. dp[A][B + 1] = min(dp[A][B + 1], ind)
    */ 

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

