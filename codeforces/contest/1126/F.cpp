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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, vector<int> > pos;
    vector<vector<int> > mx(20, vector<int> (n));

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> largestBit(n + 1);
    for(int i = 1, j = 0; i <= n; i++) {
        if((1 << (j + 1)) <= i) {
            j++;
        }
        largestBit[i] = j;
    }


    auto build = [&] () {
        pos.clear();

        for(int i = 0; i < n; i++) {
            pos[a[i]].pb(i);
            mx[0][i] = a[i];
        }
    
        for(int i = 1; i < 20; i++) {
            for(int j = 0; j + (1 << i) <= n; j++) {
                int nxt = j + (1 << (i - 1));
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][nxt]);
            }
        }
    };

    build();
    


    auto range_max = [&] (int l, int r) {
        int len = r - l + 1, lbit = largestBit[len];
        return max(mx[lbit][l], mx[lbit][r - (1 << lbit) + 1]);
    };

    auto lpos = [&](int l, int r, int localmax) {
        int ind = *lower_bound(pos[localmax].begin(), pos[localmax].end(), l);
        return ind;
    };
    auto rpos = [&](int l, int r, int localmax) {
        int ind = *(--upper_bound(pos[localmax].begin(), pos[localmax].end(), r));
        return ind;
    };

    auto ok = [&](auto&& self, int l, int r) -> bool {
        if(l > r) return true;

        int localmax = range_max(l, r);
        int left = lpos(l, r, localmax);
        int right = rpos(l, r, localmax);

        // lpos and rpos are guarenteed to be in [l, r] range.
        if(left == right) {
            return false;
        }

        return self(self, l, left - 1) && self(self, right + 1, r);
    };

    if(ok(ok, 0, n - 1)) {
        cout << "0\n";
        return;
    }

    // answer is at least 1.
    int largest = range_max(0, n - 1);
    int left = lpos(0, n - 1, largest), right = rpos(0, n - 1, largest);
    
    if(left == right) {
        // we have only 1 of the largest element:
        if(left == n - 1) {
            cout << "1\n";
            cout << "1 " << largest << "\n";
            return;
        }

        if(left == 0) {
            cout << "1\n";
            cout << n << " " << largest << "\n";
            return;
        }

        // both side fails
        a[left] = a[left - 1];
        build();
        if(ok(ok, 0, n - 1)) {
            cout << "1\n";
            cout << left + 1 << " " << a[left] << "\n";
            return;
        }
        // a[left] = largest;
    }

    if(ok(ok, 0, left - 1)) {
        // left is ok
        cout << "1\n";
        cout << n << " " << largest << "\n";
        return;
    }

    if(ok(ok, right + 1, n - 1)) {
        // right is ok
        cout << "1\n";
        cout << "1 " << largest << "\n";
        return;
    }


    // both fails.
    // if(!ok(ok, 0, left - 1) && !ok(ok, right + 1, n - 1)) {
    cout << "2\n";
    cout << "1 " << largest << "\n";
    cout << n << " " << largest << "\n";
    // return;
    // }
}

int main() {
    FAST
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

