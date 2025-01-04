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
    FAST
    string s;
    cin >> s;
    int n = s.size(), ans = 0, cur = 0;
    vector<int> cnt(n + 1, 0);
    unordered_map<int, int> firstpos;
    cnt[0] = 1;
    firstpos[0] = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            cur++;
            firstpos[cur] = i;
        } else {
            firstpos.erase(cur);
            cur--;
            if(firstpos.find(cur) != firstpos.end()) {
                ans = max(ans, i - firstpos[cur]);
                cnt[i - firstpos[cur]]++;
            }
            if(firstpos.find(cur) == firstpos.end()) {
                firstpos[cur] = i;
            }
        }
    }
    cout << ans << " " << cnt[ans] << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

