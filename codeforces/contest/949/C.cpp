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

int bitcnt(int x) {
    if(x == 1) return 1;

    return bitcnt(x >> 1) + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), inds;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > 0)
            inds.pb(i);
    }

    if(inds.empty()) {
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                cout << "2 ";
            } else {
                cout << "1 ";
            }
        }
        cout << "\n";
        return;
    }



    for(int i = 0; i + 1 < inds.size(); i++) {
        int x = a[inds[i]], y = a[inds[i + 1]];
        int cnt1 = bitcnt(x), cnt2 = bitcnt(y);
        if((inds[i + 1] - inds[i]) % 2 != abs(cnt2 - cnt1) % 2) {
            cout << "-1\n";
            return;
        }
        if(x < y) {
            int j = 0;
            while((x >> j) != (y >> (cnt2 - cnt1 + j))) {
                j++;
            }

            if(inds[i + 1] - inds[i] < cnt2 - cnt1 + 2 * j) {
                cout << "-1\n";
                return;
            }

            for(int k = 1; k <= cnt2 - cnt1 + j; k++) {
                a[inds[i + 1] - k] = a[inds[i + 1] - k + 1] / 2;
            }
            for(int k = 1; k <= j; k++) {
                a[inds[i] + k] = a[inds[i] + k - 1] / 2;
            }

            for(int k = inds[i] + j + 1; k < inds[i + 1] - cnt2 + cnt1 - j; k += 2) {
                a[k + 1] = a[k - 1];
                a[k] = a[k - 1] * 2;
            }

        } else {
            int j = 0;
            while((y >> j) != (x >> (cnt1 - cnt2 + j))) {
                j++;
            }

            if(inds[i + 1] - inds[i] < cnt1 - cnt2 + 2 * j) {
                cout << "-1\n";
                return;
            }

            for(int k = 1; k <= cnt1 - cnt2 + j; k++) {
                a[inds[i] + k] = a[inds[i] + k - 1] / 2;
            }
            for(int k = 1; k <= j; k++) {
                a[inds[i + 1] - k] = a[inds[i + 1] - k + 1] / 2;
            }

            for(int k = inds[i] + cnt1 - cnt2 + j + 1; k < inds[i + 1] - j; k += 2) {
                a[k + 1] = a[k - 1];
                a[k] = a[k - 1] * 2;
            }
        }
    }

    for(int i = inds[0] - 1, j = 0; i >= 0; i--, j ^= 1) {
        if(j) {
            a[i] = a[i + 1] / 2;
        } else {
            a[i] = a[i + 1] * 2;
        }
    }

    for(int i = inds.back() + 1, j = 0; i < n; i++, j ^= 1) {
        if(j) {
            a[i] = a[i - 1] / 2;
        } else {
            a[i] = a[i - 1] * 2;
        }
    }

    for(int x : a) {
        cout << x << " ";
    }
    cout << "\n";


    /*
    4 -1 -1 10 -> 4 2 5 10
    1 -1 -1 -1 -1 -1 1 -> 1 3 5 11 23
    -> when increasing we have options. x -> 2x or 2x + 1

    iheesee ymar 1 baidlaar garaad, baga deeree deerees in irdeg uyd:

    iheesee ymar 1 baidlaar garaad, baga deeree dooroos in irdeg uyd:


    same up, same down doens't preserves. 
    same down, same up can be different. 

    either adding bit or removing bit. 
    */
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

