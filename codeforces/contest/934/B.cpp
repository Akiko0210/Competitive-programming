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
    int n, k, ind1 = 0, ind2 = 0;
    cin >> n >> k;
    vector<int> a(2 * n), l(k * 2), r(k * 2);
    vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
    vector<vector<int> > pos(n + 1);
    vector<bool> pick(2 * n, 0);
    int cnt = 0;
    
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);
        if(i < n) {
            cnt1[a[i]]++;
            if(cnt < k && cnt1[a[i]] == 2) {
                cnt++;
                pick[pos[a[i]][0]] = 1;
                pick[pos[a[i]][1]] = 1;
            }
        } else {
            cnt2[a[i]]++;
        }
    }

    for(int i = 0, j = 0; i < n && j < 2 * (k - cnt); i++) {
        if(cnt1[a[i]] == 1) {
            // debug(a[i], pos[a[i]][0], pos[a[i]][1]);
            pick[pos[a[i]][0]] = 1;
            pick[pos[a[i]][1]] = 1;
            j++;
        }
    }

    for(int i = n; i < n * 2; i++) {
        if(cnt > 0 && cnt2[a[i]] == 2) {
            // debug(i, a[i]);
            pick[pos[a[i]][0]] = 1;
            pick[pos[a[i]][1]] = 1;
            cnt2[a[i]] = 0;
            cnt--;
        }
    }

    for(int i = 0; i < 2 * n; i++) {
        if(pick[i]) {
            if(i < n) {
                l[ind1++] = a[i];
            } else {
                r[ind2++] = a[i];
            }
        }
    }


    for(int x : l) {
        cout << x << " ";
    }
    cout << "\n";

    for(int x : r) {
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

