#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
// https://cses.fi/problemset/task/1687

/*
brute force: 
answer 1 query takes O(n), overall runtime takes O(n^2) where n is the # nodes

binary lifting:
for each node, store log n entries for the parents 
when we get k, do a binary decomposition on k, and jump accordingly
For example 
k = 6 (110) = 2 + 4; first jump 2 levels up, then jump 4 levels up
*/
 
#define endl  "\n"
using namespace std; 

const int mx = 2e5+5;
const int LOG = 25;
vector <int> par (mx);
int up[mx][LOG];

void solve (int e, int k) {
    // then process each query (e, k)
    for (int bit = 0; bit < LOG; ++bit) {
        // use 1LL here in case bit left shifting causes integer overflow
        if ((1LL<<bit) & k) {
            // take the jump 
            if (e == -1) break;
            e = up[e][bit];
        }
    }
    cout << e << endl;
}

int32_t main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    par[1] = -1;
    for (int i = 2; i <= n; ++i) {
        cin >> par[i];
    }

    // pre-compute up matrix
    for (int i = 1; i <= n; ++i) {
        // 2 ^ 0 = 1, it's just the parent
        up[i][0] = par[i];
    }

    for (int p = 1; p < LOG; ++p) {
        for (int i = 1; i <= n; ++i) {
            // temp = node i 's previous jump to 2^ (p-1) level
            // we are only storing 2^0 (parent level), 2^1, 2^2 .... , 2^k levels up
            int temp = up[i][p-1];
            if (temp == -1) {
                up[i][p] = -1;
            } else {
                up[i][p] = up[temp][p-1];
            }
        }
    }

    while (q--) {
        int e, k;
        cin >> e >> k;
        solve(e, k);
    }

    return 0; 
}