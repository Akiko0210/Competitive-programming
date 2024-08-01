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

bool p[300000];
vector<int> primes;
int k;

void sieve() {
    for(ll i = 2; i < 300000; i++) {
        if(!p[i]) {
            primes.pb(i);
            for(ll j = i * i; j < 300000; j += i) {
                p[j] = 1;
            }
        }
    }
}
/*
0
0 0
0 0 1 -> 1
0 0 



*/


int dfs(int ind, int prev, vector<vector<bool > >& edges, vector<int>& ans, vector<int>& stagemax) {
    debug(ind, prev);
    if(ind == ans.size()) {
        return 1;
    }
    int items = 0, val = 0;

    for(int x = 0; x < k; x++) {
        if(edges[prev][x]) {
            edges[prev][x] = 0;
            edges[x][prev] = 0;
            int nums = dfs(ind + 1, x, edges, ans, stagemax); 
            debug(nums);
            if(nums > stagemax[ind]) {
                val = x;
                stagemax[ind] = nums;
            }
            edges[prev][x] = 1;
            edges[x][prev] = 1;
        }
    }
    ans[ind] = primes[val];
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return items + 1;
}

void solve() {
    int n;
    cin >> n;
    /*
        a[i] <= 3e5
        a[i] * a[i + 1] != a[j] * a[j + 1]
        minimum distinct numbers. 

        every two adjacent number product is unique. 

        1 1 2 2 3 3 1 4 4 2

        4 * 4 / 2 = 8
        1 1 2 2 3 3 4 1 3

        1 2 3 4 1 3
        
        1 2 3 4 5 1 4 2 5 3 1 -> 11 + 5 = 5 * 4 / 2 + 5 + 1

        1 2 3 4 5 6 1 3 5 2 4 1 5 

        1 - 2 3 4 6 5
        2 - 1 3 5 6
        3 - 1 2 4 5
        4 - 1 3 5 6
        5 - 2 3 4 6 1
        6 - 1 5 2 4

        1 - 2 3 6
        2 - 1 3 4 5 6
        3 - 1 2 4 5
        4 - 2 3 5 6
        5 - 2 3 4 6 
        6 - 1 2 4 5


        // n = even => n + (n * (n - 2) + 2) / 2
        n + (n ^ 2 - 2n + 2) / 2 = n^2/2 - n + 1 + n = n^2 / 2 + 1

        n * n / 2 + 1
        20

        4 -> 4 + (4 * 2 + 2) / 2 = 9

        // n = odd => n + n * (n - 1) / 2
        n * (n + 1) / 2

        1 1
        2 2 
        3 3 
        1 2
        1 3
        2 3

        1 - 1
        2 - 1, 2
        3 - 2, 3, 1
        4 - 1 4 

        1 1 4 2 2 3 3 1 4 4
        4 * 4 / 2
        1 - 1 2 3 4
        2 - 1 2 3 4
        3 - 1 2 3 4
        4 - 1 2 3 4
        4 * 5 / 2 = 10

        (m % 2 == 1 ? m * (m + 1) / 2 : m * m / 2 + 1)  
    */
    k = 1;
    int sum = 2;
    while(sum < n) {
        k++;
        if(k & 1) {
            sum = k + k * (k - 1) / 2 + 1;
        } else {
            sum = k + k * (k - 2) / 2 + 2;
        }
    }

    vector<vector<bool> > edges(k + 1, vector<bool> (k + 1, 1));
    vector<int> ans(n, 0), stagemax;
    stagemax = ans;
    ans[0] = primes[0];
    dfs(1, 0, edges, ans, stagemax);
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    FAST

    sieve();
    cout << primes.size() << "size\n";
    // for(int x : primes) {
    //     cout << x << " ";
    // }
    // cout << "\n";

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

