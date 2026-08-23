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
    char gate;
    vector<Node*> children;
    bool val;
    Node(char gate) {
        this->gate = gate;
    }
    Node() {
    }

};

int dfs(Node* root, bool eval) {
    if(root->children.size() == 0) {
        return root->val != eval;
    }

    if(eval) {
        // we want true
        if(root->gate == 'A') {
            int ans = 0;
            for(auto &child : root->children) {
                int res = dfs(child, eval);
                ans += res;
            }
            return ans;
        } 
        int ans = 1000000;
        for(auto &child : root->children) {
            int res = dfs(child, eval);
            ans = min(ans, res);
        }
        return ans;
    }


    // we want false
    if(root->gate == 'A') {
        int ans = 1000000;
        for(auto &child : root->children) {
            int res = dfs(child, eval);
            ans = min(ans, res);
        }
        return ans;
    } 
    int ans = 0;
    for(auto &child : root->children) {
        int res = dfs(child, eval);
        ans += res;
    }
    return ans;
}

bool evaluate(Node *cur) {
    if(cur->children.size() == 0) {
        return cur->val;
    }

    if(cur->gate == 'A') {
        for(auto &node : cur->children) {
            if(!evaluate(node)) {
                return false;
            }
        }
        return true;
    }
    for(auto &node : cur->children) {
        if(evaluate(node)) {
            return true;
        }
    }
    return false;
}

void solve() {
/*
4 A
3
2 3 3
3 F T F T F T T
T T T
*/

    int n;
    char start;
    cin >> n >> start;
    Node* root = new Node();
    queue<Node*> current;
    current.push(root);

    for(int i = 0; i < n; i++) {
        queue<Node*> nxt_level;
        while(!current.empty()) {
            auto cur = current.front();
            current.pop();
            string in;
            cin >> in;
            if(in == "T" || in == "F") {
                cur->val = (in == "T");
            } else {
                cur->gate = start;
                int size = stoi(in);
                for(int j = 0; j < size; j++) {
                    Node* node = new Node();
                    cur->children.pb(node);
                    nxt_level.push(node);
                }
            }
        }
        current = nxt_level;
        start = (start == 'A' ? 'O' : 'A');
    }

    bool first_eval = evaluate(root);
    cout << dfs(root, !first_eval) << "\n";
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

