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
    int n;
    cin >> n;
    vector<int> to(n + 1), indegree(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> to[i];
        indegree[to[i]]++;
    }

    vector<int> peel;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) peel.pb(i);
    }

    vector<bool> inCycle(n + 1, true);
    vector<int> dis(n + 1, 0);
    for(int i = 0; i < peel.size(); i++) {
        inCycle[peel[i]] = false;
        debug(peel[i]);
        indegree[to[peel[i]]]--;
        if(indegree[to[peel[i]]] == 0) {
            peel.pb(to[peel[i]]);
        }
    }

    for(int i = 1; i <= n; i++) {
        // debug(i);
        if(inCycle[i] && dis[i] == 0) {
            debug(i);
            int start = to[i], size = 1;
            while(start != i) {
                // debug(start);
                size++;
                start = to[start];
            }
            start = to[i];
            while(start != i) {
                dis[start] = size;
                start = to[start];
            }
            dis[start] = size;
        }
    }

    for(int i = peel.size() - 1; i >= 0; i--) {
        dis[peel[i]] = dis[to[peel[i]]] + 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

