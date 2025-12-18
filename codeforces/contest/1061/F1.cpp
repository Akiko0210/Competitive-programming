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
    // debug(n);
    vector<int> p(n);
    vector<int> pos(n + 1, -1);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    auto operation = [&] (int x) {
        int a = pos[x], b = pos[x - 1], c = pos[x - 2];
        if(a > b || a > c) {
            return false;
        }
        p[a] -= 2;
        p[b]++;
        p[c]++;
        pos[p[a]] = a;
        pos[p[b]] = b;
        pos[p[c]] = c;
        return true;
    };

    int cur = 3;
    /*
    when you do operation on x, you can't do operation on any other number except x-2. 
    */ 

    while(cur <= n) {
        while(operation(cur)) {
            cur -= 2;
        }
        cur++;
    }

    for(int x : p) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
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

