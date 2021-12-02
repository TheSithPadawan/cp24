#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
// https://cses.fi/problemset/task/1688

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
const int mx = 2e5 + 5;
vector <int> v[mx];
vector <int> depth(mx);

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;

    for (const auto v: v[node]) {
        if (v == par) continue;
        dfs(v, node);
    }
}

int jump (int e, int k) {
    // jump node e to k levels above
    for (int bit = 0; bit < LOG; ++bit) {
        // use 1LL here in case bit left shifting causes integer overflow
        if ((1LL<<bit) & k) {
            // take the jump 
            if (e == -1) break;
            e = up[e][bit];
        }
    }
    return e;
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
        v[i].push_back(par[i]);
        v[par[i]].push_back(i);
    }

    // index by depth 
    depth[0] = -1;
    dfs(1, 0);

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
        int a, b;
        cin >> a >> b;
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        // lift b to a
        b = jump(b, depth[b] - depth[a]);
        if (a == b) {
            // we are done here, a is the parent of b
            cout << a << endl;
            continue;
        }
        int l = 0, r = depth[a] - 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (jump(a) == jump(b)) {
                // try go lower 
                ans = jump(a);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}