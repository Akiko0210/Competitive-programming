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

struct Node {
    int cnt;
    double W, P;
    Node *next, *prev;
    Node(){
        next = NULL;
        prev = NULL;
    }
    Node(double w, double p, int c) {
        W = w;
        P = p;
        cnt = c;
        next = NULL;
        prev = NULL;
    }

    Node* mergeNext() {
        W += next->W;
        P = next->P;
        cnt += next->cnt;
        Node* res = new Node(W, P, cnt);
        if(prev != NULL) {
            prev->next = res;
        }
        if(next->next != NULL) {
            next->next->prev = res;
        }
        res->next = next->next;
        res->prev = prev;
        return res;
    }

    Node* mergePrev() {
        W += prev->W;
        P = prev->P;
        cnt += prev->cnt;
        Node* res = new Node(W, P, cnt);
        if(next != NULL) {
            next->prev = res;
        }
        if(prev->prev != NULL) {
            prev->prev->next = res;
        }
        res->prev = prev->prev;
        res->next = next;
        return res;
    }

    double prevSpace() {
        if(prev == NULL) {
            return 1e18;
        }
        return P - prev->P;
    }

    double nextSpace() {
        if(next == NULL) {
            return -1e18;
        }
        return P - next->P;
    }

};

int main() {
    int n;
    cin >> n;
    map<double, Node*> m;
    unordered_set<double> vis;
    priority_queue<pair<double, double> > pq;
    vector<Node*> a(n);
    double torque = 0;
    for(int i = 0; i < n; i++) {
        double p, w;
        cin >> p >> w;
        torque += p * w;
        a[i] = new Node(w, p, 1);
        m[p] = a[i];
        pq.push({w, p});
        if(i > 0) {
            a[i]->prev = a[i - 1];
        }
    }
    for(int i = 0; i < n - 1; i++) {
        a[i]->next = a[i + 1];
    }

    double ans = 0;
    while(torque != 0) {
        auto cur = pq.top();
        pq.pop();

        double pos = cur.second;
        // debug(pos, torque);
        if(vis.find(pos) != vis.end()) {
            continue;
        }
        // debug("here");
        vis.insert(pos);

        Node* curNode = m[pos];
        double mass = curNode->W, unitDis = torque / mass;
        double maxDisAvailable = (torque > 0 ? curNode->prevSpace() : curNode->nextSpace());

        // debug(mass, maxDisAvailable, torque);
        if(fabs(unitDis) > fabs(maxDisAvailable)) {
            torque -= mass * maxDisAvailable;
            ans += fabs(maxDisAvailable) * curNode->cnt;
            m.erase(pos);
            Node* temp = (torque > 0 ? curNode->mergePrev() : curNode->mergeNext());
            m.erase(temp->P);
            m[temp->P] = temp;
            pq.push({temp->W / temp->cnt, temp->P});
        } else {
            torque -= mass * unitDis;
            ans += fabs(unitDis) * curNode->cnt;
        }
    }
    cout << setprecision(6) << fixed << ans << "\n";

    return 0;
}