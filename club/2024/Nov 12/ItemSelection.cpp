#include <bits/stdc++.h>

using namespace std;

int conf(vector<int> want, vector<int> sel) {
    int n = want.size(), m = sel.size(), i = 0, j = 0, ans = 0;
    while(i < n && j < m) {
        if(want[i] == sel[j]) {
            i++;
            j++;
            continue;
        }

        ans++;
        if(want[i] < sel[j]) {
            i++;
        } else {
            j++;
        }
    }
    return ans + (n - i) + (m - j);
}



int main() {
    int n, m, s, p, q;
    cin >> n >> m >> s >> p >> q;
    s--;
    int pages = (n - 1) / m + 1;
    vector<vector<int> > want(pages), presel(pages);
    for(int i = 0; i < p; i++) {
        int x;
        cin >> x;
        int mypage = (x - 1) / m;
        presel[mypage].push_back(x);
    }

    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int mypage = (x - 1) / m;
        want[mypage].push_back(x);
    }

    int mnpage = pages, mxpage = -1, ans = 0, lastpageitems;
    if(n % m == 0) {
        lastpageitems = m;
    } else {
        lastpageitems = n % m;
    }
    for(int i = 0; i < pages; i++) {
        int conflict = conf(want[i], presel[i]);
        if(conflict == 0) continue;

        int mnop = conflict;

        mnop = min(mnop, 1 + (int)want[i].size());
        mnop = min(mnop, 1 + (i == pages - 1 ? lastpageitems : m) - (int)want[i].size());

        mnpage = min(mnpage, i);
        mxpage = max(mxpage, i);
        // cout << "On page " << i << " made " << mnop << "\n";
        ans += mnop;
    }

    if(mxpage == -1) {
        cout << "0\n";
        return 0;
    }
    
    if(mxpage <= s) {
        ans += s - mnpage;
    } else if(mnpage >= s) {
        ans += mxpage - s;
    } else {
        ans += mxpage - mnpage + min(mxpage - s, s - mnpage);
    }

    cout << ans << "\n";
    

     /*
     n is the number of items. The items have item numbers from 1 to n.
     m is the fixed number of items displayed per page.
     s is the number of the page currently displayed.
     p is the number of preselected items.
     q is the number of items you want.
    

    We can do:
    - toggle one 
    - select all 
    - deselect all
    - next page
    - prev page


    --------------
    - Ignore the pages that are already done. 

    - We'll visit the pages that we need to make changes eventually. 
        if all leftie, s - min shift.
        if all rightie, max - s shift. 
        if mn < s < mx, mx - mn
    - On each page, calculate min op. 
        1. deselect all then select what i need. -> 1 + |want|
        2. select all, then deselect the ones that I don't want. -> 1 + m - |want|
        3. |preselected| + |want| - |preselected and want|

    */



    return 0;
}