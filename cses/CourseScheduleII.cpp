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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n + 1);
    vector<int> indegree(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[b].pb(a);
        indegree[a]++;
    }

    priority_queue<int> peel;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            peel.push(i);
        }
    }

    vector<int> ans;
    while(!peel.empty()) {
        int cur = peel.top();
        peel.pop();

        ans.pb(cur);
        for(int x : G[cur]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                peel.push(x);
            }
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    /*
    1 5
    5 3
    5 4
    3 6
    6 7
    4 2

    7 6 3 2 4 5 1 8 
    2 4 7 6 3 5 1 8

    I think we should just use Kanh's algorithms.

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

