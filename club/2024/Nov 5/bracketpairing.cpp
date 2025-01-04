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
const int N = 21;
vector<int> a;
vector<unordered_map<int, ll> > dp(N);
int n;

ll rec(int skey, int ssize, int ind) {
    if(ind == n) {
        // the end.
        return skey == 0;
    }

    if(n - ind < ssize) {
        // even if rest are all closing brackets, we can't close all.
        return 0;
    }

    if(dp[ind].count(skey)) {
        // calculated before
        return dp[ind][skey];
    }

    dp[ind][skey] = 0;

    if(a[ind] > 0) {
        // opening bracket.
        return dp[ind][skey] = rec(skey * 5 + a[ind], ssize + 1, ind + 1);
    }

    if(a[ind] < 0) {
        // closing bracket.
        if(ssize == 0 || skey % 5 != -a[ind]) 
            return dp[ind][skey] = 0;
        
        // successfully closes the last bracket on the stack. 
        return dp[ind][skey] = rec(skey / 5, ssize - 1, ind + 1);
    }

    // question mark.
    if(ssize > 0) // check closing
        dp[ind][skey] += rec(skey / 5, ssize - 1, ind + 1);
    
    for(int i = 1; i <= 4; i++) {
        dp[ind][skey] += rec(skey * 5 + i, ssize + 1, ind + 1);
    }

    return dp[ind][skey];
}

int main() {
    /*
    1. convert brackets into integers.
        - openings with positive ints (1 - 4)
        - closings with negative ints (1 - 4)
        - ? with 0
    2. brute force with optimization.

    Optimizations:
        - stack of brackets.
            - at i, if -1, we can add (1 - 4) or pop 
        - similar scenerios.
        - length at most 20
        - max stack size 10 -> each scenerios can be 
          represented within 4^10 ~ 1M 
        
    Hard optimizations:
        - see suffix and check matching ?

    
    */ 
    string s;
    cin >> s;
    n = s.size();
    string str_keys = "()<>[]{}?";
    int int_keys[] = {1, -1, 2, -2, 3, -3, 4, -4, 0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (int)str_keys.size(); j++) {
            if(str_keys[j] == s[i]) {
                a.pb(int_keys[j]);
                break;
            }
        }
    }

    cout << rec(0, 0, 0) << "\n";



    


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

