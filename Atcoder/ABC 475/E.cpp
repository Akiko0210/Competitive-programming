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
const int K = 201;

class TrieNode {
public:
    int cnt;
    TrieNode* children[2];

    // Constructore to initialize a trie node
    TrieNode()
    {
        cnt = 0;
        children[0] = children[1] = NULL;
    }
};

// class for the Trie implementation
class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word)
    {
        TrieNode* node = root;
        for (char c : word) {
            int index = (c == 'o');
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node->cnt++;
            node = node->children[index];
        }
        node->cnt++;
    }

    // Function to delete a word from the trie
    void deleteWord(string word)
    {
        TrieNode* node = root;
        for (char c : word) {
            int index = (c == 'o');
            if (!node->children[index]) {
                return;
            }
            node->cnt--;
            node = node->children[index];
        }
        node->cnt--;
    }

    int search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = (c == 'o');
            if (!node->children[index]) {
                return 0;
            }
            node = node->children[index];
        }
        return node->cnt;
    }
};

void solve() {
    FAST

    int n, m, k;
    string t;
    cin >> n >> m >> k >> t;
    vector<string> students(n);

    // bitset<K> ans_key = tobitset(t);
    // vector<string> s(n);
    // vector<bitset<K> > key(n);
    // vector<unordered_map<bitset<K>, int> > cnt(k);
    
    // auto remove = [&] (int ind) {
    //     bitset<K> temp(0);
    //     for(int i = 0; i < k; i++) {
    //         temp[i] = key[ind][i];
    //         cnt[i][temp]--;
    //     }
    // };

    // auto add = [&](int ind) {
    //     bitset<K> temp(0);
    //     for(int i = 0; i < k; i++) {
    //         temp[i] = key[ind][i];
    //         cnt[i][temp]++;
    //     }
    // };

    Trie trie;

    auto check = [&](int ind) -> bool {
        // bitset<K> match(0);
        string match = "";
        int slots = m;
        for(int i = 0; i < k && slots > 0; i++) {
            // match[i] = ans_key[i];
            match += t[i];
            int cnt = trie.search(match);
            if(cnt <= slots) {
                // all qualify
                if(students[ind][i] == t[i]) {
                    // cout << "qualified in round: " << i << "\n";
                    return true;
                }
                slots -= cnt;
                match[i] = (t[i] == 'o' ? 'x' : 'o');
            } else {
                // all the other not qualify
                if(students[ind][i] != t[i]) {
                    // cout << "dis-qualified in round: " << i << "\n";
                    return false;
                }
            }
        }
        return false;
    };

    for(int i = 0; i < n; i++) {
        cin >> students[i];
        trie.insert(students[i]);
    }

    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        // remove(a);
        trie.deleteWord(students[a]);
        // key[a][b] = !key[a][b];
        students[a][b] = (students[a][b] == 'o' ? 'x' : 'o');
        trie.insert(students[a]);
        // add(a);

        // qualifier run
        if(check(a)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
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

