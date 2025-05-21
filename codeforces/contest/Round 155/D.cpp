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

const ll MOD = 998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 0; i < 31; i++) {
        ll base = (1 << i), cur = 0, sum = 0;
        ll cnt[2];
        ll cntsum[2];
        cnt[0] = cnt[1] = 0;
        cntsum[0] = cntsum[1] = 0;

        for(int j = 0; j < n; j++) {
            int b = a[j] >> i & 1;
            cur ^= b;
            cnt[cur]++;
            cntsum[cur] += j;
            (sum += (j) * cnt[cur ^ 1] - cntsum[cur ^ 1] + cur * (j + 1)) %= MOD;
        }
        (ans += base * sum % MOD) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}

/*
    1. Let's solve the problem for each bit of each number.
    
    2. So, for i-th bit we get binary array, and what we need 
    calculate is sum of ranges of intervals that has odd number
    of bits in it. And let's call this answer for i-th bit as 
    sum[i].

    3. In order to calculate sum[i], let's solve the problem for
    some fixed r, that means we calculate only intervals that 
    starts from arbitrary index j and ends at r. Let's say the answer
    for this question as sumAt[r].

    4. Let's say we have prefix array such that prefix[i] is
    true if the number of bits in interval [0, i]. Then the 
    things starts to get little clear. the interval [i + 1, r] has
    odd number of bits only if prefix[i] + prefix[r] = 1.

    5. So the the fixed value r, we have to calculate the sum of
    ranges of intervals such that left position is i and
    prefix[i] + prefix[r] = 1.

    6. Let's say we also have presum[i][j] array such that 
    presum[i][j] equals the sum of k where prefix[k] equals
    j when k <= i. And also say we have cnt[i][j] array such that
    cnt[i][j] equals the number of k that prefix[k] equals j
    when k <= i.

    7. Finally we can calculate our answer for fixed r in an
    instant. that is sumAt[r] = r * cnt[r][prefix[r] ^ 1] - 
    presum[r][prefix[r] ^ 1] + prefix[r] * (r + 1).
    prefix[r] * (r + 1) is for, if to total number of bits until
    r is odd, we can take interval [0, r]. We can process
    prefix, presum, cnt arrays as we traverse through the r.

    8. Now we can solve the bigger problem as we run r from 0 to
    n - 1 and increase the sum[i] by sumAt[r]. 

    9. Remember we solved the problem for i-th bit, so we should
    add sum[i] * (1 << i) to the answer. And that's it!.
*/ 

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
