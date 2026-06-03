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

vector<int> nums;

int count () {
    int ans = 0;
    for(int i = 0; i < 1e7; i++) {
        vector<int> d(7, 0);
        int j = 6, x = i;
        bool can = true;
        while(x) {
            d[j] = x % 10;
            if(j < 6 && d[j] > d[j + 1]) {
                can = false;
                break;
            }
            j--;
            x /= 10;
        }
        // for(int j = 1; j < 7; j++) {
        //     if(d[j] < d[j - 1]) {
        //         can = false;
        //         break;
        //     }
        // }
        if(can) {
            nums.pb(i);
        }
        ans += can;
    }
    return ans;
}

int main() {
    for(int x : nums) {
        cout << x << " ";
    }
    cout << "\n";
    cout << count() << "\n";
    
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

