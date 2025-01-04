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

int d;
vector<int> a;


int calc(vector<bool>& took) {
    int lcm = 1, cnt = 0;
    for(int i = 0; i < 4; i++)
        if(took[i]) {
            cnt++;   
            lcm = lcm * a[i] / gcd(lcm, a[i]);
            // debug(a[i]);
        }
    
    if(cnt == 0) return 0;
    int res = (cnt & 1 ? 1 : -1) * d / lcm;
    // debug(cnt, res);
    return res;
}

int rec(int ind, vector<bool>& took) {
    if(ind == 4) {
        return calc(took);
    }

    int ans = rec(ind + 1, took);
    took[ind] = 1;
    ans += rec(ind + 1, took);
    took[ind] = 0;
    return ans;
}

int main() {
    a.resize(4);
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    cin >> d;
    vector<bool> took(4, 0);
    cout << rec(0, took) << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

