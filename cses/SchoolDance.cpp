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
const int N = 1000;
int n, m, k;
vector<vector<int> > cap;
vector<vector<bool> > matching;


int get_flow() {
    // source: 0, sink : n + m + 1
    // find route

    queue<int> q;
    vector<int> pre(n + m + 2, -2);
    pre[0] = -1;
    q.push(0);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == n + m + 1) {
            break;
        }

        for(int i = 0; i <= n + m + 1; i++) {
            if(cap[cur][i] > 0 && pre[i] == -2) {
                pre[i] = cur;
                q.push(i);
            }
        }
    }

    if(pre[n + m + 1] == -2) {
        return 0;
    }

    int cur = n + m + 1;
    // vector<int> vis;

    while(pre[cur] != -1) {
        // debug(cur);
        // flow = min(flow, cap[pre[cur]][cur]);
        cap[pre[cur]][cur] -= 1;
        cap[cur][pre[cur]] += 1;
        // vis.pb(cur);
        
        if(cur != n + m + 1 && pre[cur] != 0) {
            matching[cur][pre[cur]] = !matching[cur][pre[cur]];
            matching[pre[cur]][cur] = !matching[pre[cur]][cur];
        }
        cur = pre[cur];
    }
    // vis.pb(cur);
    // reverse(vis.begin(), vis.end());

    // for(int i = 0; i < vis.size() - 1; i++) {
    //     cap[vis[i]][vis[i + 1]] -= flow;
    //     cap[vis[i + 1]][vis[i]] += flow;
    // }

    return 1;
}

int max_matching() {
    int flow = get_flow(), ans = 0;
    while(flow > 0) {
        ans += flow;
        flow = get_flow();
    }
    return ans;
}

int main() {
    cin >> n >> m >> k;
    cap.assign(N + 5, vector<int> (N + 5, 0));
    matching.assign(N + 5, vector<bool> (N + 5, 0));


    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cap[a][n + b] = 1;
    }

    for(int i = 1; i <= n; i++) {
        cap[0][i] = 1;
    }
    for(int i = n + 1; i <= n + m; i++) {    
        cap[i][n + m + 1] = 1;
    }

    cout << max_matching() << "\n";

    for(int i = 1; i <= n; i++) {
        for(int j = n + 1; j <= n + m; j++) {
            if(matching[i][j]) {
                cout << i << " " << j - n << "\n";
            }
        }
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

