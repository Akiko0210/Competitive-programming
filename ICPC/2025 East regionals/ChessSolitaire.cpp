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

string types = "NBQRK";

struct Board {
    int x, y, id;
    Board(string loc, int ind) {
        x = loc[0] - 'A';
        y = loc[1] - '1';
        id = ind;
    }

    string getStr() {
        string res = "";
        res.push_back(char(x + 'A'));
        res.push_back(char(y + '1'));
        return res;
    }
};

struct Piece {
    Board* location;
    int type;

    Piece(int t, Board* loc) {
        type = t;
        location = loc;
    }

    bool reachable(Board* other, vector<Piece*>& pieces) {
        // cout << "checking : " << types[type] << " at " << location->getStr() << " moving to " << other->getStr() << "\n";
        // knight
        if(type == 0) {
            if(abs(other->x - location->x) == 1 && abs(other->y - location->y) == 2) 
                return true;
            if(abs(other->x - location->x) == 2 && abs(other->y - location->y) == 1) 
                return true;
            return false;
        }
        // king
        if(type == 4) {
            if(abs(other->x - location->x) <= 1 && abs(other->y - location->y) <= 1)
                return true;
            return false;
        }

        auto same_diag = [](Board* a, Board* b) {
            return abs(a->x - b->x) == abs(a->y - b->y);
        };

        auto same_row = [](Board* a, Board* b) {
            return a->x == b->x;
        };
        auto same_col = [](Board* a, Board* b) {
            return a->y == b->y;
        };

        auto diag_check = [&](Board* location, Board* other) {
            if(same_diag(location, other)) {
                int mnx = min(other->x, location->x), mxx = max(other->x, location->x);
                int mny = min(other->y, location->y), mxy = max(other->y, location->y);
                for(auto &p : pieces) {
                    if(!same_diag(location, p->location)) continue;

                    if(mnx < p->location->x && p->location->x < mxx &&
                       mny < p->location->y && p->location->y < mxy
                    ) {
                        // cout << p->location->getStr() << "it's getting in a way\n";
                        return false;
                    }
                }
                return true;
            }
            return false;
        };

        auto row_check = [&](Board* location, Board* other) {
            if(same_row(location, other)) {
                int mny = min(other->y, location->y), mxy = max(other->y, location->y);
                for(auto &p : pieces) {
                    if(!same_row(location, p->location)) continue;

                    if(mny < p->location->y && p->location->y < mxy) {
                        // cout << p->location->getStr() << "it's getting in a way\n";
                        return false;
                    }
                }
                return true;
            }
            return false;
        };

        auto col_check = [&](Board* location, Board* other) {
            if(same_col(location, other)) {
                int mnx = min(other->x, location->x), mxx = max(other->x, location->x);
                for(auto &p : pieces) {
                    if(!same_col(location, p->location)) continue;

                    if(mnx < p->location->x && p->location->x < mxx) {
                        // cout << p->location->getStr() << "it's getting in a way\n";
                        return false;
                    }
                }
                return true;
            }
            return false;
        };


        if(type == 1) {
            if(diag_check(location, other)) 
                return true;
            
            return false;
        }

        if(type == 2) {
            if(diag_check(location, other) || col_check(location, other) || row_check(location, other)) 
                return true;
            
            return false;
        }

        if(type == 3) {
            if(col_check(location, other) || row_check(location, other))
                return true;
            return false;
        }
        return false;
    }

    string move(Board* other) {
        string res = "";
        res.push_back(types[type]);
        res = res + ": " + location->getStr() + " -> " + other->getStr();
        location = other;
        return res;
    }
};

unordered_map<ll, bool> is_pos;

vector<ll> pw(10, 1);

ll my_hash(vector<Piece*>& pieces) {
    ll res = 0;
    for(auto& p : pieces) {
        res += pw[(p->location->id)] * (p->type + 1);
    }
    return res;
}

vector<string> ans;

bool solve(vector<Piece*> pieces) {
    if(pieces.size() == 1) {
        return true;
    }
    ll hash_value = my_hash(pieces);

    if(is_pos.count(hash_value)) {
        return is_pos[hash_value];
    }
    sort(pieces.begin(), pieces.end(), [](Piece* a, Piece* b) {
        return a->location->getStr() < b->location->getStr();
    });

    int n = pieces.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            if(pieces[i]->reachable(pieces[j]->location, pieces)) {
                // cout << "succeed\n";
                // i can capture j.
                vector<Piece*> next_pieces = pieces;
                Piece* movingPiece = next_pieces[i];
                Board* prev_loc = movingPiece->location;
                string cur_move = movingPiece->move(pieces[j]->location);
                swap(next_pieces[n - 1], next_pieces[j]);
                next_pieces.pop_back();
                
                if(solve(next_pieces)) {
                    ans.pb(cur_move);
                    return is_pos[hash_value] = true;
                }
                movingPiece->location = prev_loc;
            }
        }
    }

    return is_pos[hash_value] = false;
}

int main() {
    for(int i = 1; i < 10; i++) {
        pw[i] = pw[i - 1] * 10;
    }

    int n, m;
    cin >> n >> m;
    vector<Piece*> pieces;
    for(int i = 0; i < m; i++) {
        char p;
        string loc;
        cin >> p >> loc;
        Board* newboard = new Board(loc, i);
        int type = types.find(p);
        Piece* newpiece = new Piece(type, newboard);
        pieces.pb(newpiece);
    }

    // sort(pieces.begin(), pieces.end(), [](Piece* a, Piece* b) {
    //     return a->location->getStr() < b->location->getStr();
    // });

    if(solve(pieces)) {
        while(!ans.empty()) {
            cout << ans.back() << "\n";
            ans.pop_back();
        }
    } else {
        cout << "No solution\n";
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

