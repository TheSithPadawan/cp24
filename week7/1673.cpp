#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
#define endl  "\n"
#define NEG_INF LLONG_MIN

using namespace std; 

/*
https://cses.fi/problemset/task/1673
Algo:
Bellman ford + positive cycle detection
Trick is that the positive cycle might not connect to the source
Detect this by doing DFS from node n to see if it can reach the cycle
*/

const int maxN = 2501;
const int maxM = 5001;

vector <int> g[maxN];
// reverse graph
vector <int> gr[maxN];
// edges <src, dst, weight>
vector <tuple<int, int, int>> edges;
int n, m, q;
vector <int> dist;
set <int> nodes;
set <int> visited;

bool optimize()
{
    bool flag = false;
    // return true if there is a positive cycle
    for (int k = 0; k < n-1; ++k) {
        for (const auto [i, j, w]: edges) {
            if (dist[i] == NEG_INF) continue;
            if (dist[i] + w > dist[j]) {
                dist[j] = dist[i] + w;
            }
        }
    }
    
    // last update for postive cycle detection 
    // flag nodes that are in the positive cycle
    for (const auto [i, j, w]: edges) {
        if (dist[i] == NEG_INF) continue;
        if (dist[i] + w > dist[j]) {
            flag = true;
            nodes.insert(j);
            dist[j] = dist[i] + w;
        }
    }
    return flag;
}

void dfs(int node) {
    if (visited.find(node) != visited.end()) {
        return;
    }
    visited.insert(node);

    for (int v: gr[node]) {
        dfs(v);
    }
}


int32_t main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);

	cin >> n >> m;
    
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), NEG_INF);

	for(int i = 0 ; i < m ; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
        edges.push_back({a, b, w});
        // build reverse graph
        gr[b].push_back(a);
 	}
 
    dist[1] = 0;
    bool res = optimize();
    if (!res) {
        cout << dist[n] << endl;
        return 0;
    }
    // a second check
    /*
    run DFS from node n in reverse graph,
    see if nodes in the positive cycles are reachable
    if so, return -1
    */
    dfs(n);
    for (const auto node: nodes) {
        if (visited.find(node) != visited.end()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << dist[n] << endl;
    return 0; 
}