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

vector<int> generatePrimes(int n) {
    vector<bool> isprime(n + 1, true);
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(isprime[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<int> value(n);
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }

    vector<int> primes = generatePrimes(n);
    int thresHold = sqrt(n) + 1;
    vector<int> A, B;
    for(int x : primes) {
        if(x <= thresHold) {
            A.push_back(x);
        } else {
            B.push_back(x);
        }
    }


    // |A| <= 16
    int maskBits = A.size();
    int maxMask = (1 << maskBits) - 1;
    vector<int> dp(maxMask + 1, 0);
    int m = B.size();
    vector<vector<int> > groups(m);

    auto get_mask = [&](int x) {
        int mymask = 0;
        for(int j = 0; j < maskBits; j++) {
            if(x % A[j] == 0) {
                mymask |= (1 << j);
            }
        }
        return mymask;
    };

    for(int i = 2; i <= n; i++) {
        // we can consider i if it's representable by using only A.
        int temp = i;
        for(int x : A) {
            while(temp % x == 0) {
                temp /= x;
            }
        }
        
        if(temp == 1) {
            // we should consider i
            // we need to create the mask for i
            int mymask = get_mask(i);
            
            for(int mask = 0; mask <= maxMask; mask++) {
                if((mymask & mask) == mymask) {
                    dp[mask] = max(dp[mask], dp[mask ^ mymask] + value[i - 1]);
                }
            }
        } else {
            for(int j = 0; j < m; j++) {
                
                if(i % B[j] == 0) {
                    // i should go to x's group
                    groups[j].push_back(i);
                }
            }
        }
    }


    // second part
    for(int i = 0; i < m; i++) {
        vector<int> prevdp = dp;
        for(int x : groups[i]) {
            // find mask
            int mymask = get_mask(x);
            for(int mask = 0; mask <= maxMask; mask++) {
                if((mask & mymask) == mymask) {
                    dp[mask] = max(dp[mask], prevdp[mask ^ mymask] + value[x - 1]);
                }
            }
        }
    }

    cout << dp[maxMask] + value[0] << "\n";
        

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

