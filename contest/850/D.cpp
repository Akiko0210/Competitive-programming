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

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > mat(n, (3, 0));
    vector<pii> W(n, {0, 0}), I(n, {0, 0}), N(n, {0, 0});
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        W[i].ss = i;
        I[i].ss = i;
        N[i].ss = i;
        
        for(char c : s) {
            if(c == 'w') {
                mat[i][0]++;
                W[i].ff++;
            }
            if(c == 'i') {
                mat[i][1]++;
                I[i].ff++;
            }
            if(c == 'n') {
                mat[i][2]++;
                N[i].ff++;
            }
        }
    }
    sort(W.begin(), W.end());
    sort(I.begin(), I.end());
    sort(N.begin(), N.end());

    map<pii, pair<char, char> > ans;

    auto solve = [&] (char c, vector<pii> a) {
        int l = 0, r = n - 1;
        while(l < r){
            while(a[r].ff > 1) {
                a[l].ff++;
                a[r].ff--;
                int ind1 = min(a[l].ss, a[r].ss), ind2 = max(a[l].ss, a[r].ss);
                auto el = ans[{ind1, ind2}];
                if(a[r].ss == ind2) {
                    el.ss = c;
                } else {
                    el.ff = c;
                }
                ans[{ind1, ind2}] = el;
            }
            r--;
        }
    }

}

int main() {
    int t;
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
