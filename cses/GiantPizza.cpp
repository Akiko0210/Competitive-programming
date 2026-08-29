// 2SAT

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

int n, m;

int rev(int x) {
    return x >= m ? x - m : x + m;
}

struct Trojan {
    int n;
    vector<int> low, id;
    vector<bool> instack;
    stack<int> s;
    vector<vector<int> > components, G;

    Trojan(int n, vector<vector<int> >& G) {
        this->G = G;
        this->n = n;
        low.resize(n);
        id.resize(n, -1);
        instack.resize(n, false);

        int counter = 0;
        for(int i = 0; i < n; i++) {
            dfs(i, counter);
        }
    }

    void dfs(int cur, int& counter) {
        if(id[cur] != -1) {
            return;
        }

        id[cur] = low[cur] = counter++;
        instack[cur] = true;
        s.push(cur);

        for(int x : G[cur]) {
            dfs(x, counter);
            if(instack[x]) {
                low[cur] = min(low[cur], low[x]);
            }
        }

        if(low[cur] == id[cur]) {
            vector<int> component;
            while(s.top() != cur) {
                low[s.top()] = low[cur];
                instack[s.top()] = false;
                component.pb(s.top());
                s.pop();
            }

            instack[cur] = false;
            component.pb(cur);
            components.pb(component);
            s.pop();
        }
    }

};

int main() {
    cin >> n >> m;
    vector<vector<int> > G(m * 2);
    for(int i = 0; i < n; i++) {
        char c1, c2;
        int t1, t2;
        cin >> c1 >> t1 >> c2 >> t2;
        t1--, t2--;
        if(c1 == '-') {
            t1 = rev(t1);
        }
        if(c2 == '-') {
            t2 = rev(t2);
        }

        // debug(t1, t2, rev(t1), rev(t2));

        G[rev(t1)].pb(t2);
        G[rev(t2)].pb(t1);
    }

    Trojan scc(m * 2, G);

    // cout << "here\n";
    vector<int> value(m * 2, -1);
    for(int i = 0; i < m; i++) {
        if(scc.low[i] == scc.low[rev(i)]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for(auto &component : scc.components) {
        for(int x : component) {
            if(value[x] == -1) {
                value[x] = 1;
                value[rev(x)] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(value[i] == 1) {
            cout << "+ ";
        } else {
            cout << "- ";
        }
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

