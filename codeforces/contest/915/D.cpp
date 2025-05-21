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
    int n, zpos;
    cin >> n;
    vector<int> a(n), b(n), pos(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] == 0) zpos = i;
    }
    for(int i = 0; i < n; i++) {
        a[i] = b[(zpos + i) % n];
        pos[a[i]] = i;
    }



    for(int i = 0; i < n; i++) {
        b[i] = i - 1;
        while(b[i] >= 0 && a[b[i]] >= a[i]) {
            b[i] = b[b[i]];
        }
    }
    // cout << "here\n";

    vector<int> seq;
    // int ind = n - 1;
    // while(ind >= 0) {
    //     seq.pb(a[b[ind]]);
    // }

    // reverse(seq.begin(), seq.end());
    ll cur = 0, ans = 0;
    // for(int i = 1; i < seq.size(); i++) {
    //     cur += (pos[seq[i]] - pos[seq[i - 1]]) * seq[i];
    // }

    for(int i = n - 1; i >= 0; i--) {
        int ind = i;
        vector<int> temp;
        while((ind >= 0 && seq.empty()) || (!seq.empty() && ind > pos[seq.back()])) {
            temp.pb(a[ind]);
            ind = b[ind];
        }
        while(!temp.empty()) {
            if(!seq.empty()) {
                cur += (ll)temp.back() * (pos[temp.back()] - pos[seq.back()]);
            }
            seq.pb(temp.back());
            temp.pop_back();
        }
        // for(int x : seq) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        ans = max(ans, cur);
        int last = seq.back();
        seq.pop_back();
        if(!seq.empty())
            cur -= (ll)(pos[last] - pos[seq.back()]) * last;
    }
    cout << ans + n << "\n";



    /*
        1. start from 0.
        2. remove elements from back 1 by 1.
        3. nearest lower element
        4. 
    */



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

