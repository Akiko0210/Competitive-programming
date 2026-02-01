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

    vector<vector<int> > dp;
    vector<int> a;

    int rec(int l, int r) {
        if(l == r) return dp[l][r] = 1;
        if(dp[l][r] < 1e9) return dp[l][r];

        for(int j = l; j < r; j++) {
            int lval = rec(l, j), rval = rec(j + 1, r);
            // few more factors.
            dp[l][r] = min(lval + rval - (a[l] == a[r]), dp[l][r]);
        }
        return dp[l][r];
    }

    void solve() {
        /*
        12 -> 2
        121 -> 2
        1212 -> 3

        Actions made on the corners are independent. 
        That means, you can do that at the very end or at the very beginning.
        You can make only 1 end independent?

        1 3 3 4 3 1 5 2
        1 3 -> 2
        1 3 3 -> 2
        1 3 3 4 -> 3
        1 3 3 4 3

        3 2 1 2 3 1 2 3
        1 2 3 -> 3
        1 2 3 1 -> 3.
        2 1 2 3 -> 

        If it matches with just 1 end, then it's a free loader. 
        */

        int n;
        cin >> n;
        a = vector<int> (n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        a.insert(a.begin(), 0);
        a.push_back(0);
        n += 2;
        // we also kind of only care about the different numbers. 
        // but let's ignore that for now. 

        dp = vector<vector<int> > (n, vector<int> (n, 1e9));
        cout << rec(0, n - 1) - 1 << "\n";
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

