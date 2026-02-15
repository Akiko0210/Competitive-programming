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

struct P {
    int x, y;
    P(int a, int b) {
        x = a;
        y = b;
    }
    P(){}
};

P operator -(P a, P b) {
    return P(a.x - b.x, a.y - b.y);
}
P operator +(P a, P b) {
    return P(a.x + b.x, a.y + b.y);
}
bool operator ==(P a, P b) {
    return a.x == b.x && a.y == b.y;
}

ll cross(P a, P b, P p) {
    // base ab
    P r = b - a, s = p - a;
    return (ll)r.x * s.y - (ll)r.y * s.x;
}

int orientation(P a, P b, P c) {
    // a -> b -> c
    // is c on the left or on the right.
    ll o = cross(a, b, c);
    return o == 0 ? 0 : (o > 0 ? -1 : 1);
    // clockwise -> -1
    // counterclock -> 1;
}

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    P start;
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        if (i == 0 || 
            points[i].x < start.x || 
            (points[i].x == start.x && points[i].y < start.y
        )){
            start = points[i];
        } 
    }

    sort(points.begin(), points.end(), [&](P a, P b) {
        int o = orientation(start, a, b);
        if(o == 0) {
            int dx = abs((a - start).x) - abs((b - start).x);
            int dy = abs((a - start).y) - abs((b - start).y);
            if(dx < 0) return true;
            if(dx > 0) return false;

            return dy < 0;
        }

        return o > 0;
    });



    vector<P> convexHull = {start, points[1]};
    
    auto clearhull = [&](P p) {
        int cur = convexHull.size() - 1;
        int o = orientation(convexHull[cur - 1], convexHull[cur], p);
        while(o <= 0 && cur > 0) {
            convexHull.pop_back();
            cur = convexHull.size() - 1;
            o = orientation(convexHull[cur - 1], convexHull[cur], p);
        }
    };

    for(int i = 2; i < n; i++) {
        clearhull(points[i]);
        convexHull.pb(points[i]);
    }
    clearhull(start);

    // cout << "Convex Hull:\n";
    // for(P p : convexHull) {
    //     cout << p.x << "  " << p.y << "\n";
    // }

    int m = convexHull.size();
    ll maxArea = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 2; j < m; j++) {
            /*
                line from i to j is base.
            */ 

            int l = i + 1, r = j - 1;
            while(l < r) {
                int mid = (l + r) / 2;
                ll aream = abs(cross(convexHull[i], convexHull[j], convexHull[mid]));
                ll areanext = abs(cross(convexHull[i], convexHull[j], convexHull[mid + 1]));
                if(aream < areanext) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if(l == r) {
                maxArea = max(maxArea, abs(cross(convexHull[i], convexHull[j], convexHull[l])));
            }
        }
    }
    cout << fixed << setprecision(2) << double(maxArea) / 2 << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

