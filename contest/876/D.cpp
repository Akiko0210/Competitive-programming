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

vector<int> pathOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> sub, subIndex; 
    vector<int> path(n, -1); 
    for (int i = 0; i < n; ++i) {
        if (sub.empty() || sub[sub.size() - 1] <= nums[i]) {
            path[i] = sub.empty() ? -1 : subIndex[sub.size() - 1];
            sub.push_back(nums[i]);
            subIndex.push_back(i);
        } else {
            int idx = upper_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
            path[i] = idx == 0 ? -1 : subIndex[idx - 1];
            sub[idx] = nums[i];
            subIndex[idx] = i;
        }
    }
    vector<int> ans;
    int t = subIndex[subIndex.size() - 1];
    while (t != -1) {
        ans.push_back(nums[t]);
        t = path[t];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ind(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }
    vector<int> lis = pathOfLIS(a);
    if(lis.size() == 1) {
        for(int i = 0; i < n; i++) {
            cout << n - 1 << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i <= ind[lis[0]]; i++) {
        if(a[i] <= lis[1]) {
            lis[0] = a[i];
            break;
        }
    }

    vector<int> mv;
    int lis_ind = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != lis[lis_ind]) {
            mv.pb(i);
        } else {
            lis_ind++;
        }
    }

    int m = mv.size(), range = mv.back() - mv[0];
    vector<int> dp(m), dp1(m);
    for(int k = 1; k <= n; k++) {
         
    }



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
