#include <bits/stdc++.h>

using namespace std;

int main() {
    int mx = 100000, n = (mx - 1) / 3 * 2 + 2;
    cout << n << endl;
    vector<int> ind(mx + 1, -2);
    ind[0] = 1;
    ind[mx] = n;

    for(int i = 3; i < mx; i += 3) {
        ind[i] = i / 3 * 2 + 1;
    }

    auto add = [&](int in) {
        if(ind[in] != -2) return;
        
        int section = (in - 1) / 3;
        int base = (section + 1) * 2;
        ind[in] = -1;
        ind[3 - in % 3 + section * 3] = base;
    };

    int in;
    cin >> in;
    while(in != -1) {
        add(in);
        cout << ind[in] << endl;
        cin >> in;
    }

    for(int i = 0; i <= mx; i++) {
        add(i);
        if(ind[i] >= 0) {
            cout << i << endl;
        }
    }



    return 0;
}