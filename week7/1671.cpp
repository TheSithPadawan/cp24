#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
#define endl  "\n"
using namespace std; 

/*
https://cses.fi/problemset/task/1671
Algo:
Use Dijkstra's algo to compute shortest
route from 1 to all other nodes (priority queue)
*/

vector <vector <pair<int, int>>> g;
vector <int> dist;
vector <int> vis;

int n, m;

struct Comp {
  bool operator () (const pair <int, int> & a, const pair <int, int> & b) {
    return a.first > b.first;
  }
};

void bfs()
{
    // custom comparator, order by edge weight decreasing
    // item are indexed by (dist, node id) source has distance 0
	pq <pair<int, int>, vector<pair<int,int>>, Comp> Q;
    // enqueue starting point
    Q.push({0, 1});
    dist[1] = 0;

	while(!Q.empty())
	{
		auto [d, node] = Q.top();
		Q.pop();
        if (vis[node]) continue;
        vis[node] = 1;
		//visit the breadth of this element
        for (const auto e: g[node]) {
            int cur = d + e.second;
            if (cur < dist[e.first]) {
                dist[e.first] = cur;
                Q.push({dist[e.first], e.first});
            }
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

	cin >> n >> m;
    g.resize(n+1);
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), LLONG_MAX);
    vis.resize(n+1);

	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
        g[a].push_back({b,c});
	}

    bfs();

	for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0; 
}