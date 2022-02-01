#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
#define INF LLONG_MAX
 
 
 
#define endl  "\n"
using namespace std; 

const int M = 2e5 + 5;
const int N = 1e5 + 5;
// record cost
vector <int> cost(N, INF);
vector <int> costR(N, INF);
// graph
vector <pair<int, int>> g[M];
vector <pair<int, int>> gr[M];
vector <bool> visited(N, false);
vector <bool> visitedR(N, false);
vector <tuple<int, int, int>> edges;

struct Comp {
  bool operator () (const pair <int, int> & a, const pair <int, int> & b) {
    return a.second > b.second;
  }
};

void optimize(int node, const vector <pair<int, int>> * graph, vector <bool> & vis, vector <int> & c)
{
    // use dijkstra to optimize
    
    pq <pair<int, int>, vector<pair<int,int>>, Comp> q;
    q.push({node, 0});
    c[node] = 0;
    while (!q.empty()) {
        auto [cur, y] = q.top();
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        for (const auto [nei, weight]: graph[cur]) {
            if (y + weight < c[nei]) {
                c[nei] = y + weight;
                q.push({nei, c[nei]});
            }
        }
    }    
}

void relax_edge(int n) {
    // for each edge (u, v), relax the cost
    for (const auto [u, v, w]: edges) {
        int new_cost = w/2;
        if (cost[u] == INF || costR[v] == INF) continue;
        int new_total = cost[u] + new_cost + costR[v];
        // update
        if (new_total < cost[n]) {
            cost[n] = new_total;
        }
    }
}


int32_t main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);

    int n , m;
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		edges.push_back({a, b, w});
        g[a].push_back({b, w});
        gr[b].push_back({a, w});
	}
    // first pass optimize on original graph, from source to everyone else
	optimize(1, g, visited, cost);    
    // second pass optimize on reverse graph, from destination to everyone else
    optimize(n, gr, visitedR, costR);
    relax_edge(n);
    cout << cost[n] << endl;
    return 0; 
}