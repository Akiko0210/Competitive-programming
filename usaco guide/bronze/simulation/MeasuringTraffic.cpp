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

pii final_range(vector<vector<int> >& a, int n) {
    bool seen = false;
    int l = 0, r = 1000;
    for(int i = 0; i < n; i++) {
        if(a[i][0] == 0 && !seen) continue;

        if(a[i][0] == 1) {
            seen  = true;
            l = max(l, a[i][1]);
            r = min(r, a[i][2]);
            continue;
        }
        if(a[i][0] == 0) {
            l += a[i][1];
            r += a[i][2];
        } else {
            l -= a[i][2];
            r -= a[i][1];
        }
        l = min(1000, l);
        l = max(0, l);
        r = min(1000, r);
        r = max(0, r);
    }

    return {l, r};
}

int main() {
    ifstream cin("traffic.in");
    ofstream cout("traffic.out");

    int n;
    cin >> n;

    vector<vector<int> > a(n, vector<int> (3));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s >> a[i][1] >> a[i][2];

        if(s == "on")
            a[i][0] = 0;
        if(s == "off") 
            a[i][0] = 2;
        if(s == "none")
            a[i][0] = 1;
    }

    pii last_pos = final_range(a, n);
    for(int i = 0; i < n; i++) {
        a[i][0] = 2 - a[i][0];
    }
    reverse(a.begin(), a.end());

    pii first_pos = final_range(a, n);
    cout << first_pos.ff << " " << first_pos.ss << "\n" << last_pos.ff << " " << last_pos.ss << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

