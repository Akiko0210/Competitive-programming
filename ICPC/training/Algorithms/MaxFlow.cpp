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

struct Edge {
    int t, w;
    Edge* re;
    Edge(int target, int weight) {
        t = target;
        w = weight;
    }
};

class Graph {
    private:
        int n, m;
        vector<vector<Edge*>> G;
    public:
        Graph() {
            cin >> n >> m;
            G.resize(n);
            // vector<vector<int>> mat;
            // mat.resize(n, vector<int> (n, 0));
            // mat.resize(n);
            for(int i = 0; i < m; i++) {
                int a, b, c;
                cin >> a >> b >> c;
                a--;
                b--;
                Edge* e1 = new Edge(b, c);
                Edge* e2 = new Edge(a, 0);
                e1->re = e2;
                e2->re = e1;
                G[a].push_back(e1);
                G[b].push_back(e2);
            }
            
            // for(int i = 0; i < n; i++) {
            //     for(int j = 0; j < n; j++) {
            //         if(mat[i][j] > 0) {
            //             cout << i + 1 << " " << j + 1 << " " << mat[i][j] << "\n";
            //             Edge e1(j, mat[i][j]);
            //             Edge e2(i, 0);
            //             e1.re = &e2;
            //             e2.re = &e1;
            //             G[i].push_back(e1);
            //             G[j].push_back(e2);
            //         }
            //     }
            // }
        }

        int get_flow() {
            // 0: server
            // n - 1: Kotivalo's pc

            vector<Edge*> parEdge(n, NULL);
            vector<int> par(n, -2);
            queue<int> q;
            q.push(0);
            par[0] = -1;
            bool found = false;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                if(cur == n - 1) {
                    found = true;
                    break;
                }
                for(Edge* e : G[cur]) {
                    if(par[e->t] == -2 && e->w > 0) {
                        q.push(e->t);
                        parEdge[e->t] = e;
                        par[e->t] = cur;
                    }
                }
            }
            if(!found) {
                return 0;
            }

            vector<Edge*> res;
            int cur = n - 1, min_w = INF;
            while(cur != 0) {
                // cout << cur << " ";
                res.push_back(parEdge[cur]);
                min_w = min(min_w, parEdge[cur]->w);
                cur = par[cur];
            }
            // cout << "\n";
            

            for(Edge* e : res) {
                e->w -= min_w;
                e->re->w += min_w;
            }
            return min_w;
        }

        ll max_flow() {
            ll ans = 0, cur = get_flow();
            while(cur > 0) {
                ans += cur;
                cur = get_flow();
            }
            return ans;
        }


};

int main() {
    Graph G;
    cout << G.max_flow() << "\n";
    return 0;
}