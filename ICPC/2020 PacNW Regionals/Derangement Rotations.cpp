#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    /*
    F(D) = number of distinct rotations of D that are also dearrangements
    given n, find the number of dearrangements D s.t F(D) = n - 2

    n = 3
    pos D: {{2, 1, 3}, {2, 3, 1}, {3, 1, 2}}
    second and third dearrangements are rotations of each other.

    So, every dearrangements, we can rotate them till it start with 1 and make that a key.
    in given unique key space, how many of them have n - 2 dearranged rotations?

    for a dearrangement, for every element if we note the their offsets.
    for every unique offset rotation, we'll get 1 non-dearrangement (since that index will be matched)

    So we're looking for a dearrangement that has exactly 2 unique offset. 
    Let's say every dearrangement that has the same key rotations of each other.

    Each one of that n - 2 dearranged rotations has also F(D) = n - 2.
    So for every valid (i, j) pairs, we have n - 2 answer.

    But we can't choose i and j arbitrarily. 
    Valid (i, j):
    1. i != j
    2. 
    let's say i offset is set to A and j set to B.
    i -> A
    b -> B

    A was initially supposed to be at position A. by shifted i, now it's at (A + i) % n (thinking our permutation is from 0 to n - 1)
    so for i and j, (A + i) % n != (B + j) % n because they can't clash with each other. They can't share the same spot.

    Remember we're not just shifting 2 element A and B. we're applying i or j to every element of the permutation.
    let's say:
    A = numbers that got i applied = {A0, A1, A2, ...}
    B = numbers that got j applied = {B0, B1, B2, ...}

    A0 + i - j = A1
    A1 + i - j = A2
    A2 + i - j = A3
    ...
    Ak + i - j = A0

    how many i - j steps form n cycle? It has to strictly less than n.

    B0 + j - i = B1
    B1 + j - i = B2
    B2 + j - i = B3
    ...
    Bm + j - i = B0

    (k + 1) + (m + 1) = n.

    for x steps to form cycle n, it takes exactly n / gcd(n, x) steps.
    So, we can preprocess for every x.

    S(x) = n / gcd(n, x) = size of the set.

    for every x, if S(x) + S(n - x) = n, this x is an answer. 
    We can choose (i, j) s. t i > j and i - j = x  n - x different ways.

    Let's test it on 6. 
    S(1) = 6
    S(2) = 3
    S(3) = 2
    S(4) = 3
    S(5) = 6

    for x = 2, we have 4 pairs:
    for (1, 3):
    A = {1, 3, 5}
    B = {2, 4, 6}
    1 -> 2
    3 -> 4
    5 -> 6
    2 -> 5
    4 -> 1
    6 -> 3

    (4, 6) and (2, 6) pairs aren't valid
    for each pair, we have 2 possible dearrangements. So x = 6 gives us 4 * 2. but it's not enough? 
    (4 valid pairs) * (2 swaps) = 8.

    for x = 3? 
    for (1, 4):
    A = {1, 4, 3, 6}
    B = {2, 5}

    or we can have:
    A = {1, 4}
    B = {2, 5, 3, 6}

    basically 3 set of groups, split into 2 -> 3 ways.
    so in total, (3 + 2) * 4 = 20 ways

    let's see n = 3.
    S(1) = 3
    S(2) = 3

    There's no (i, j) pair.  -> 0

    n = 4:
    S(1) = 4
    S(2) = 2
    S(3) = 4

    x = 2 works -> (1, 3).
    A = {1, 3}
    B = {2, 4}
    suggesting 4 dearrangeds:
    [x, x, x, x]
    [2, 1, 4, 3] (1, 3)
    [4, 3, 2, 1] (3, 1)

    ------------
    n = 4 brute force count:
    [2, 1, 4, 3] -> [1, 4, 3, 2] -> (0, 2)
    [2, 3, 4, 1] -> [1, 2, 3, 4] -> (0)
    [2, 4, 1, 3] -> [1, 3, 2, 4] -> (0, 1, 3)
    [3, 1, 4, 2] -> [1, 4, 2, 3] -> (0, 2, 1)
    [3, 4, 1, 2] -> [1, 2, 3, 4] -> (0)
    [3, 4, 2, 1] -> [1, 3, 4, 2] -> (0, 3, 2)
    [4, 1, 2, 3] -> [1, 2, 3, 4] -> (0)
    [4, 2, 1, 3] -> [1, 3, 4, 2] -> (0, 3, 2)
    [4, 3, 1, 2] -> [1, 2, 4, 3] -> (0, 3, 1)
    [4, 3, 2, 1] -> [1, 4, 3, 2] -> (0, 2)

    So my guess now is for every valid ordered (i, j) pair, there are n - 2 possibles.
    now concern is how to not undercount or overcount?
    
    Let's test it on 8:
    S(1) = 8
    S(2) = 4
    S(3) = 8
    S(4) = 2
    S(5) = 8
    S(6) = 4
    S(7) = 8

    Let's test it on 12:

    S(1) = 12
    S(2) = 6
    S(3) = 4
    S(4) = 3
    S(5) = 12
    S(6) = 2
    S(7) = 12
    S(8) = 3
    S(9) = 12
    S(10) = 6
    S(11) = 12

    x = 2 -> 2 ways. 
    x = 3 -> C(3, 2) = 3 ways
    x = 4 -> C(4, 2) = 6 ways
    x = 6 -> C(6, 2) = 15 ways

    4 1 6 3 2 5
    

    1 2 3 4 5 6
    */
    ll n, p;
    cin >> n >> p;

    vector<ll> pw(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2 % p;
    }

    ll ans = 0;
    for(int i = 1; i <= n / 2; i++) {
        // ans increment by 
        ll groupsize = n / gcd(n, i);
        ll groups = n / groupsize;
        ll add = (pw[groups - 1] + (p - 1)) * (n - 2) % p;
        if(i * 2 != n) add = add * 2 % p;

        ans = (ans + add) % p;
    }

    /*

    1, 2, 3 to 2 box
    2^(3 - 1) - 1
    2^(2 - 1) - 1
    
    x = 3 gives us 3 groups to put into 2 boxes.
    1, 4
    2, 5
    3, 6

    A = {1, 4, 3, 6}
    B = {2, 5}
    A = {1, 4, 2, 5}
    B = {3, 6}
    A = {1, 4}
    B = {2, 5, 3, 6}

    // (i, j) = (1, 4)
    2 5 4 1
    6 3

    // (i, j) = (4, 1)
    5 2 1 4
    3 6


    x = 2 gives us 2 groups to put into 2 boxes.
    1 3 5
    2 4 6

    // (i, j) = (1, 3)
    2 4 6
    5 1 3

    // 


    000
    001
    010
    011
    
    00
    01
    
    10
    11

    100
    101
    110
    111

    1000000 305919461
expected: 31185737
found: 31999936

    
    */

    cout << ans << "\n";


    return 0;
}