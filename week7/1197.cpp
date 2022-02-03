#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
#define endl  "\n"
#define INF LLONG_MAX

using namespace std; 

/*
https://cses.fi/problemset/task/1197
Algo:
- Bellman ford + negative cycle detection
- record the parent of each relaxation during bellman ford
- Use |v|-1  trace backs to end up in the original cycle and print
*/

const int maxN = 2501;
const int maxM = 5001;

vector <pair<int, int>> g[maxN];
vector <tuple<int, int, int>> edges;
int n, m, q, C;
vector <int> dist;
set <int> nodes;
set <int> visited;
vector <int> cycles;
vector <int> parent(maxN, -1);

bool optimize()
{
    bool flag = false;
    // return true if there is a positive cycle
    for (int k = 0; k < n-1; ++k) {
        for (const auto [i, j, w]: edges) {
            if (dist[i] == INF) continue;
            if (dist[i] + w < dist[j]) {
                dist[j] = dist[i] + w;
                parent[j] = i;
            }
        }
    }
    
    // last update for negative cycle detection 
    // flag nodes that are in the negative cycle
    for (const auto [i, j, w]: edges) {
        if (dist[i] == INF) continue;
        if (dist[i] + w < dist[j]) {
            flag = true;
            dist[j] = dist[i] + w;
            parent[j] = i;
            C = j;
            break;
        }
    }
    return flag;
}

void dfs(int node) {
    if (visited.find(node) != visited.end()) {
        return;
    }
    visited.insert(node);

    for (const auto [v, y]: g[node]) {
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
    fill(dist.begin(), dist.end(), INF);

	for(int i = 0 ; i < m ; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
        edges.push_back({a, b, w});
        // build reverse graph
        g[a].push_back({b,w});
 	}
    
    vector <int> src;
    for (int i = 1; i <= n; ++i) {
        if (visited.find(i) != visited.end()) continue;
        dfs(i);
        src.push_back(i);
    }

    for (const int j: src) {
        dist[j] = 0;
    }

    visited.clear();
    bool res = optimize();
    if (!res) {
        cout << "NO" << endl;
        return 0;
    }
    // print cycle
    cout << "YES" << endl;
    /*
    reverse n-1 times guarantees goes back to the cycle 
    */
   
    for (int i = 0; i < n-1; i++) {
        C = parent[C]; 
    }
  
    int v = C;
    while (1) {
        cycles.push_back(v);
        if (v == C && cycles.size() > 1) break;
        v = parent[v];
        if (v == -1) break;
    }
    reverse(cycles.begin(), cycles.end());
    for (const auto u: cycles) {
        cout << u << " ";
    }
    cout << endl;
    return 0; 
}