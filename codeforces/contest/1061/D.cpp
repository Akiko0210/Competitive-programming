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

bool query(int i, int x) {
    cout << "? " << i << " " << x << endl;
    bool res;
    cin >> res;
    return res;
}

int cntbit(int l, int x) {
    int first_half = l / (x * 2);
    int rem = l % x + 1;
    return first_half * x + ((l & x) ? rem : 0);
}

void solve() {
    int n, x = 1, ans = 0;
    cin >> n;

    vector<int> pos(n - 1), candidates(n);
    iota(pos.begin(), pos.end(), 1);
    iota(candidates.begin(), candidates.end(), 1);

    
    while(x <= n) {
        // ans is in range [l, r]
        // debug(l, r);
        vector<int> a, b;
        int expected1 = 0, expected0 = 0;
        for(int candidate : candidates) {
            if(x & candidate) {
                expected1++;
            } else {
                expected0++;
            }
        }

        for(int j = 0; j < pos.size(); j++) {
            int i = pos[j];
            bool res = query(i, x);
            if(res) {
                // has 1
                a.push_back(i);
            } else {
                // has 0
                b.push_back(i);
            }
        }
        vector<int> next_candidates;
        if(a.size() == expected1) {
            // has 0
            for(int candidate : candidates) {
                if(!(candidate & x)) next_candidates.push_back(candidate);
            }
            pos = b;
        } else {
            // has 1
            for(int candidate : candidates) {
                if(candidate & x) next_candidates.push_back(candidate);
            }
            pos = a;
        }
        candidates = next_candidates;
        x *= 2;
    }
    cout << "! " << candidates[0] << endl;
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

