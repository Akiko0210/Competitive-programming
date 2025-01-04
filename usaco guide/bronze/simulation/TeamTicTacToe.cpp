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

int main() {
    ifstream cin("tttt.in");
    ofstream cout("tttt.out");

    vector<string> a(3);
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }


    vector<bool> ind(26, 0);
    vector<vector<bool> > team(26, vector<bool> (26, 0));
    auto claimAnswer = [&] (set<char> s) {
        if(s.size() == 1) {
            ind[*s.begin() - 'A'] = 1;
        }
        if(s.size() == 2) {
            char f = *s.begin();
            s.erase(f);
            char t = *s.begin();
            debug(f, t);
            team[f - 'A'][t - 'A'] = 1;
        }
    };

    set<char> d, rd;
    for(int i = 0; i < 3; i++) {
        d.insert(a[i][i]);
        rd.insert(a[i][2 - i]);
        set<char> row, col;
        for(int j = 0; j < 3; j++) {
            row.insert(a[i][j]);
            col.insert(a[j][i]);
        }
        claimAnswer(row);
        claimAnswer(col);
    }
    claimAnswer(d);
    claimAnswer(rd);

    int cnt = 0;
    for(bool x : ind) {
        cnt += x;
    }
    cout << cnt << "\n";
    cnt = 0;
    for(auto line : team) {
        for(bool x : line) {
            cnt += x;
        }
    }
    cout << cnt << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

