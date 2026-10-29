#include <bits/stdc++.h>

using namespace std;

const int MAX_BIT = 160;

bitset<MAX_BIT> convert(string &s) {
    int n = s.size();
    bitset<MAX_BIT> ans;
    for(int i = 0; i < n; i++) {
        int val;
        if(s[i] >= '0' && s[i] <= '9') {
            val = s[i] - '0';
        } else {
            val = s[i] - 'a' + 10;
        }

        ans = (ans << 4);
        ans |= val;
    }

    return ans;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bitset<MAX_BIT>> basis(k * 4);
    vector<int> time(k * 4, -1);
    int ztime = -1;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bitset<MAX_BIT> b = convert(s);
        for(int j = k * 4 - 1; j >= 0; j--) {
            // can't be basis of j
            if(!b[j]) continue;

            if(basis[j] != 0) {
                b ^= basis[j];
            } else {
                basis[j] = b;
                time[j] = i + 1;
                break;
            }
        }
        if(b == 0 && ztime == -1) ztime = i + 1;
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        bitset<MAX_BIT> b = convert(s);
        if(b == 0) {
            if(ztime != -1) {
                cout << ztime << "\n";
            } else {
                cout << "-1\n";
            }
            continue;
        }
        int last = -1;
        for(int j = k * 4 - 1; j >= 0; j--) {
            if(!b[j]) continue;

            if(basis[j] != 0) {
                last = max(last, time[j]);
                b ^= basis[j];
            }
        }

        if(b == 0) {
            cout << last << "\n";
        } else {
            cout << "-1\n";
        }
    }


    return 0;
}