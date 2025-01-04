#include <bits/stdc++.h>

using namespace std;
int n, m;

array<int, 3> xrot(array<int, 3> cur) {
    return {cur[0], cur[2], n + 1 - cur[1]};
}

array<int, 3> yrot(array<int, 3> cur) {
    return {n + 1 - cur[2], cur[1], cur[0]};
}

array<int, 3> zrot(array<int, 3> cur) {
    return {cur[1], n + 1 - cur[0], cur[2]};
}

int topos(array<int, 3> cur) {
    return cur[0] + (cur[1] - 1) * n + (cur[2] - 1) * n * n;
}

int main() {
    cin >> n >> m;
    /*
    ***G* 
    *****
    *****
    *****
    *****

    *****
    G****
    *****
    *****
    *****

    (1, 4) -> (2, 1)
    (i, j) -> (n + 1 - j, i)
    */

    array<int, 3> (*rotations[])(array<int, 3>) = {xrot, yrot, zrot};
    vector<bool> isquery(m, 0);
    vector<array<int, 3> > ops, pos;
    for(int i = 0; i < m; i++) {
        char dir;
        int x, y, z;
        cin >> dir >> x >> y;
        if(dir == 'q') {
            cin >> z;
            ops.push_back({x, y, z});
            isquery[i] = 1;
        } else {
            ops.push_back({dir == 'x' ? 0 : dir == 'y' ? 1 : 2, x / 90, y});
        }
    }

    for(int i = m - 1; i >= 0; i--) {
        if(isquery[i]) {
            pos.push_back(ops[i]);
            continue;
        }

        // rotations. 
        // cout << ops[i][0] << " axis " << ops[i][1] << " times after " << ops[i][2] << "\n";
        for(auto &el : pos) {
            // cout << el[0] << " " << el[1] << " " << el[2] << "\n"; 
            if(el[ops[i][0]] > ops[i][2]) {
                // cout << "rotates\n";
                // reverse rotates
                for(int j = 0; j < 4 - ops[i][1]; j++) {
                    el = rotations[ops[i][0]](el);
                }
                // cout << el[0] << " " << el[1] << " " << el[2] << " is new location\n\n"; 
            }
        }
    }


    while(!pos.empty()) {
        cout << topos(pos.back()) << "\n";
        pos.pop_back();
    }





    return 0;
}