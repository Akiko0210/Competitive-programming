#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

#define f first
#define s second
#define bk back()
#define pb push_back

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)

int N, Q;

const int MX = 2e5 + 5;

using T = long long;  // or long long
const T EPS = 1e-9;   // might want to change
using P = pair<T, T>;
using vP = vector<P>;
using Line = pair<P, P>;

T sq(T a) { return a * a; }                       // square
T norm(const P &p) { return sq(p.f) + sq(p.s); }  // x^2 + y^2

// basic operations
P operator-(const P &l, const P &r) { return P(l.f - r.f, l.s - r.s); }

T cross(const P &a, const P &b) { return a.f * b.s - a.s * b.f; }  // cross product
T cross(const P &p, const P &a, const P &b) {                      // cross product
	return cross(a - p, b - p);
}

using vi = vector<int>;
using vP = vector<P>;

vi hullInd(const vP &v) {
	int ind = int(min_element(all(v)) - begin(v));
	vi cand, hull{ind};
	F0R(i, sz(v)) if (v[i] != v[ind]) cand.pb(i);

	sort(all(cand), [&](int a, int b) {  // sort by angle, tiebreak by distance
		P x = v[a] - v[ind], y = v[b] - v[ind];
		T t = cross(x, y);
		return t != 0 ? t > 0 : norm(x) < norm(y);
	});

	trav(c, cand) {  // for every point
		while (sz(hull) > 1 && cross(v[end(hull)[-2]], v[hull.bk], v[c]) <= 0) {
			hull.pop_back();  // pop until counterclockwise and size > 1
		}
		hull.pb(c);
	}

	return hull;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (;;) {
		int n;
		cin >> n;
		if (!n) break;
		vP pts(n);

		F0R(i, n) {
			long long a, b;
			cin >> a >> b;
			pts[i] = P(a, b);
		}

		vi ret = hullInd(pts);  // gets hull indices of convex hull

		cout << sz(ret) << '\n';
		trav(a, ret) { cout << pts[a].first << " " << pts[a].second << '\n'; }
	}
}