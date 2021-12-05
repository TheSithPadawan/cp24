#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353

 
#define endl  "\n"
using namespace std; 
const int mx = 2e5 + 5;
vector <int> v[mx];
vector <int> depth(mx);

const int LOG = 25;
vector <int> par (mx);
int up[mx][LOG];

// https://cses.fi/problemset/task/1135

/*
Algo:
For node (a, b), find LCA(a, b) = c
dist (a, b) = depth(a, c) + depth(b, c)
overall time complexity = q * log n
*/

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

void binary_lifting(int n) {
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
}

int lca (int a, int b) {
    // returns the LCA of node a and and node b
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
        
    // lift b to a
    b = jump(b, depth[b] - depth[a]);
    if (a == b) {
        // we are done here, a is the parent of b
        return a;
    }

    for (int p = LOG-1; p >=0; p--) {
        if (up[a][p] != up[b][p]) {
            a = up[a][p];
            b = up[b][p];
        }
    }

    return up[a][0];
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
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // bfs to build the tree
    vector <int> visited(n+1);
    vector <int> dist(n+1); // this records distance of all nodes to 1
    queue <int> que;
    que.push(1);
    visited[1] = 1;
    depth[1] = 0;
    while (!que.empty()) {
        for (int i = 0; i < que.size(); ++i) {
            int node = que.front();
            que.pop();
            int cur = depth[node];
            for (const auto nei: v[node]) {
                if (visited[nei]) continue;
                visited[nei] = 1;
                depth[nei] = cur+1;
                que.push(nei);
                par[nei] = node;
            }
        }
    }

    // no need to do dfs because depth indexing is done
    binary_lifting(n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int root = lca(a, b);
        cout << depth[a] - depth[root] + depth[b] - depth[root] << endl;
    }
    return 0; 
}