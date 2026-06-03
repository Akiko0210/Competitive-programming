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

struct Node {
    int l, r;
    bool cur, isA;

    Node() {
    }
};

int main() {
    int n;
    char start;
    cin >> n >> start;
    bool isA = (start == 'A');
    vector<vector<Node*> > tree(n);
    int sum = 1;
    for(int i = 0; i < n; i++) {
        int temp = 0;
        while(sum--) {
            string t;
            cin >> t;
            // cout << t << " ";
            Node* newNode = new Node();
            if(t == "F" || t == "T") {
                newNode->isA = isA;
                newNode->cur = (t == "T");
                newNode->l = -1;
                newNode->r = -1;
                // newNode->size = 0;
            } else {
                int size = stoi(t);
                // newNode->size = size;
                newNode->isA = isA;
                newNode->l = temp;
                temp += size;
                newNode->r = temp;
                // debug(newNode->l, newNode->r);
            }
            tree[i].pb(newNode);
        }
        // cout << "\n";
        sum = temp;
        isA = !isA;
    }

    auto dfs = [&](auto&& f, int l, int i) -> int {
        // debug(l, i);
        if(tree[l][i]->l == -1) {
            // cout << "leaf\n";
            return tree[l][i]->cur;
        }
        // cout << "non-leaf\n";
        
        if(tree[l][i]->isA) {
            // cout << "is A\n";
            int res = INF;
            // debug(tree[l][i]->l, tree[l][i]->r);
            for(int j = tree[l][i]->l; j < tree[l][i]->r; j++) {
                // debug(j);
                res = min(res, f(f, l + 1, j));
            }
            return res;
        }
        // cout << "is O\n";
        int res = 0;
        for(int j = tree[l][i]->l; j < tree[l][i]->r; j++) {
            res += f(f, l + 1, j);
        }
        return res;
    };

    cout << dfs(dfs, 0, 0) << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/