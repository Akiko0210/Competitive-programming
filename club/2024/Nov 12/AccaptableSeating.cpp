#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main() {
    /*
        if 
        b[j - 1] <= a[i] <= b[j + 1]
        and
        a[i - 1] <= b[j] <= a[i + 1]

        we can swap(a[i], b[j]).
    

        we want to rearrange the students in desired order. 
        for each, a[i], there is at most 2 b[j] that can be swapped with. 
        because a[i] can fit into only 1 segment of b. Let's say that segment
        is b[j - 1] <= a[i] <= b[j]. Then b[j - 1] and b[j] are both possible candidates. 
        Among the candidates, who can fit into a[i - 1] and a[i + 1], can be swapped. 
        -> Make graph.


    */

    int r, c;
    cin >> r >> c;
    vector<pair<int, int> > posa(r * c + 1), posb(r * c + 1);
    vector<vector<int> > a(r, vector<int> (c)), b(r, vector<int> (c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            posa[a[i][j]] = {i, j};
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> b[i][j];
            posb[b[i][j]] = {i, j};
        }
    }

    vector<vector<int> > ans;

    for(int i = 1; i <= r * c; i++) {
        int ra = posa[i].first, ca = posa[i].second;
        int rb = posb[i].first, cb = posb[i].second;
        // cout << i << " #i " << ra << " " << ca << " " << rb << " " << cb << "\n";
        // cout <
        while(a[rb][cb] != i) {
            int j = lower_bound(a[ra].begin() + ca, a[ra].end(), a[rb][cb]) - a[ra].begin();
            j--;
            // for(auto row : a) {
            //     for(auto el : row) {
            //         cout << el << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
            posa[a[rb][cb]] = {ra, j};
            posa[a[ra][j]] = {rb, cb};
            swap(a[ra][j], a[rb][cb]);
            ans.push_back({ra + 1, ca + 1, rb + 1, cb + 1});
        }

        /*
            Swap condition:
            a and b are different rows. 
            if 
            b[j - 1] <= a[i] <= b[j + 1]
            and
            a[i - 1] <= b[j] <= a[i + 1]


            we're guarenteed that 0 - (i - 1) are in place. 
            That implies, a[rb][cb] > a[ra][ca] = i because every number smaller than i are in place.
            and also, a[rb][cb - 1] < i. because in the b array, b[rb][cb] is less than i and it has
            to be put into its place before i. So, that means, if a[rb][cb] < a[ra][j + 1] and
            a[rb][cb] > a[ra][j], such that j >= ca, 
            a[ra][j - 1] < a[rb][cb] < a[ra][j + 1]
            a[rb][cb - 1] < a[ra][j] < a[rb][cb + 1]


            a[ra][ca] -> a[rb][cb]

        */


    }

    cout << ans.size() << "\n";
    for(auto el : ans) {
        cout << el[0] << ' ' << el[1] << " " << el[2] << " " << el[3] << "\n";
    }


    return 0;
}