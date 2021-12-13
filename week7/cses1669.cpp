#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// problem: https://cses.fi/problemset/task/1669
/*
Algo:
	Use DFS to check for cycle in an undirected graph
*/

const int M = 1e5 + 5;
vector<int> v[M];
vector<int> vis(M);
vector <int> par(M);

int dfs(int node, int parent)
{
	/*
	returns the start of a cycle
	*/

	vis[node] = 1;
	par[node] = parent;
	for(auto x : v[node])
	{
		if (x == parent) continue;
		if(vis[x] == 0) {
			int res = dfs(x, node);
			if (res != -1) return res;
		} else {
			return x;
		}
	}
	return -1;
}

void print_path (int node, int start, vector <int> & paths)
{
	//visiting this node
	vis[node] = 1;
	paths.push_back(node);
	for(auto x : v[node])
	{
		if (x == par[node]) continue;
		if (x == start) {
			// print 
			paths.push_back(x);
			cout << paths.size() << endl;
			for (const auto v: paths) {
				cout << v << " ";
			}
			cout << endl;
			return;
		}
		if(vis[x] == 0) {
			print_path(x, start, paths);
		}
	}
	paths.pop_back();	
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
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

 	int start = -1;
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 0) {
			start = dfs(i, -1);
			if (start != -1) break;
		}
	}
	if (start == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	// print path
	fill (vis.begin(), vis.end(), 0);
	vector <int> paths;
	print_path(start, start, paths);	
    return 0; 
}