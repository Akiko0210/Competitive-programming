#include <bits/stdc++.h>

using namespace std;

bool check(string &a, string &b, int s) {
    int n = a.size(), m = b.size();
    for(int i = 0; i < s; i++) {
        if(a[n - 1 - i] != b[s - 1 - i]) {
            return false;
        }
    }

    return true;
}

string solve(string cur, vector<string>& a) {
    if(a.empty()) {
        return cur;
    }

    string last = a.back(), best = "-";
    a.pop_back();
    int n = cur.size(), m = last.size();
    for(int i = 1; i <= min(n, m); i++) {
        if(!check(cur, last, i)) continue;

        string nxt = solve(cur + last.substr(i), a);
        if(nxt != "-") {
            if(best == "-" || best.size() > nxt.size() || (best.size() == nxt.size() && best > nxt)) {
                best = nxt;
            }
        }
    }

    for(int i = 1; i <= min(n, m); i++) {
        if(!check(last, cur, i)) continue;

        string nxt = solve(last + cur.substr(i), a);
        if(nxt != "-") {
            if(best == "-" || best.size() > nxt.size() || (best.size() == nxt.size() && best > nxt)) {
                best = nxt;
            }
        }
    }

    a.push_back(last);

    return best;

}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    string ans = "-";


    do {
        string cur = a.back();
        a.pop_back();
        string res = solve(cur, a);
        a.push_back(cur);
        if(res == "-") continue;

        if(ans == "-" || ans.size() > res.size() || (ans.size() == res.size() && ans > res)) {
            ans = res;
        }

    } while(next_permutation(a.begin(), a.end()));

    cout << (ans == "-" ? "-1" : ans) << "\n";

    return 0;
}