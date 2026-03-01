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

struct Tree {
    int x, y, h;
    Tree() {

    }
    Tree(int a, int b, int c) {
        x = a;
        y = b;
        h = c;
    }
};

vector<vector<pii> > mtree;

void build(int i, int L, int R, vector<Tree>& trees) {
    if(L == R) {
        mtree[i] = {{trees[L].y, trees[L].h}};
        return;
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    build(x, L, M, trees);
    build(y, M + 1, R, trees);

    // merge
    mtree[i].resize(R - L + 1);
    int lind = 0, rind = 0;
    while(lind < mtree[x].size() && rind < mtree[y].size()) {
        if(mtree[x][lind].ff < mtree[y][rind].ff) {
            mtree[i][lind + rind] = mtree[x][lind];
            lind++;
        } else {
            mtree[i][lind + rind] = mtree[y][rind];
            rind++;
        }
    }

    while(lind < mtree[x].size()) {
        mtree[i][lind + rind] = mtree[x][lind];
        lind++;
    }
    while(rind < mtree[y].size()) {
        mtree[i][lind + rind] = mtree[y][rind];
        rind++;
    }
}

vector<int> temp;
int limit = 50;

void query(int i, int L, int R, int l, int r, int yl, int yr) {
    if(temp.size() == limit) return;

    if(l <= L && R <= r) {
        pii q = {yl, 0};
        int start = lower_bound(mtree[i].begin(), mtree[i].end(), q) - mtree[i].begin();
        q = {yr, INF};
        int end = upper_bound(mtree[i].begin(), mtree[i].end(), q) - mtree[i].begin();
        for(int j = start; j < end && temp.size() < limit; j++) {
            temp.pb(mtree[i][j].ss);
        }
        return;
    }
    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(l <= M) {
        query(x, L, M, l, r, yl, yr);
    }
    if(r > M) {
        query(y, M + 1, R, l, r, yl, yr);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    mtree.resize(n * 4);
    vector<Tree> trees(n);
    for(int i = 0; i < n; i++) {
        cin >> trees[i].x >> trees[i].y >> trees[i].h;
    }

    sort(trees.begin(), trees.end(), [](Tree a, Tree b) -> bool {
        if(a.x < b.x) {
            return 1;
        }
        if(a.x > b.x) {
            return 0;
        }
        return a.y < b.y;
    });

    // built the merge sort tree.

    build(0, 0, n - 1, trees);


    while(q--) {
        int lx, ly, hx, hy;
        cin >> lx >> ly >> hx >> hy;
        int l = lower_bound(trees.begin(), trees.end(), lx, [](const Tree& a, int x){
            return a.x < x;
        }) - trees.begin();
        int r = upper_bound(trees.begin(), trees.end(), hx, [](int x, const Tree& a){
            return x < a.x;
        }) - trees.begin();

        // debug(l, r);
        if(l > r - 1) {
            cout << "0\n";
            continue;
        }
        temp.clear();
        query(0, 0, n - 1, l, r - 1, ly, hy);
        if(temp.size() == limit) {
            cout << "1\n";
            continue;
        }
        sort(temp.begin(), temp.end());
        bool can = false;
        for(int i = 0; i + 2 < temp.size(); i++) {
            if(temp[i] + temp[i + 1] > temp[i + 2]) {
                can = true;
                break;
            }
        }
        cout << (can ? "1\n" : "0\n");
    }


    return 0;
}