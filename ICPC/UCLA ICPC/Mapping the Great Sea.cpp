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

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int> (n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<int> > mat1(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            if(a[i][j] == 1) {
                mat1[i][j] = (j == n - 1 ? 0 : mat1[i][j + 1]) + 1;
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << mat1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int type1 = 0, type2 = 0;
    vector<vector<int> > sum(n + 1, vector<int> (n + 1, 0));

    auto add = [&] (int i, int j, int w, int r) {
        type1++;
        sum[i][j]++;
        sum[i][j + w]--;
        sum[r + 1][j]--;
        sum[r + 1][j + w]++;
        // cout << i << " " << j << " " << w << " " << r << "\n";

        // for(auto row : sum) {
        //     for(int x : row) {
        //         cout << x << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n";
    };


    for(int i = 0; i < n; i++) {
        stack<tuple<int, int, int> > st;
        for(int j = 0; j < n; j++) {
            int myflag = (i == 0 ? true : (mat1[j][i - 1] == 0));
            int myval = mat1[j][i];
            /*
                gets added to stack if it has greater value or better flag.
            
            */ 
            int minind = j;
            while(!st.empty() && (get<0>(st.top()) > myval || (get<0>(st.top()) == myval && get<1>(st.top()) < myflag))) {
                auto [val, flag, ind] = st.top();
                minind = min(minind, ind);
                // 
                if(flag == 1) {
                    add(ind, i, val, j - 1);
                }
                st.pop();
            }

            if(myval != 0) {
                // update previous flags.
                if(myflag == 1) {
                    stack<tuple<int, int, int> > temp;
                    while(!st.empty() && get<1>(st.top()) == 0) {
                        auto [val, flag, ind] = st.top();
                        st.pop();
                        temp.push({val, myflag, ind});
                    }
                    while(!temp.empty()) {
                        st.push(temp.top());
                        temp.pop();
                    }
                }
                if(!st.empty() && (get<0>(st.top()) == myval && get<1>(st.top()) == myflag)) {
                    continue;
                }
                st.push({myval, myflag, minind});
            }
        }

        while(!st.empty()) {
            auto [val, flag, ind] = st.top();
            st.pop();
            if(flag == 1) {
                add(ind, i, val, n - 1);
            }
        }
    }

    // cout << type1 << "\n";
    for(int i = 0; i < n; i++) {
        sum[i + 1][0] += sum[i][0];
        sum[0][i + 1] += sum[0][i];
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<bool> > vis(n, vector<bool> (n, false));
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    auto bfs = [&] (int i, int j) {
        queue<pii> q;
        q.push({i, j});

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            vis[cur.ff][cur.ss] = true;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && sum[nx][ny] == 1 && vis[nx][ny] == false) {
                    q.push({nx, ny});
                }
            }
        }
        
        type2++;
    };


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(sum[i][j] == 1 && vis[i][j] == false) {
                bfs(i, j);
                // for(auto row : vis) {
                //     for(auto x : row) {
                //         cout << x << " ";
                //     }
                //     cout << "\n";
                // }
                // cout << "\n";
            }
        }
    }

    cout << type1 << " " << type2 << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

