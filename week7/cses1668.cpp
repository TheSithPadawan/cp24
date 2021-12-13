#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// https://cses.fi/problemset/task/1668
/*
Algo
	Use DFS to check for bipartite graph
	dfs parameter is set as (node, color)
	when a node is visited, check if the color is 
	different than its parent, rather than skip it	
*/

const int M = 2e5 + 5;
vector<int>v[M];
vector<int>vis(M);
// record which group the node is assigned to
vector <int> group (M);
const int C = 3;

bool dfs(int node, int color)
{
	//visiting this node

	vis[node] = 1;
	group[node] = color;

	for(auto x : v[node])
	{
		if(vis[x] == 0){
			bool res = dfs(x, C - color);
			if (!res) return false;
		}
		else {
			if (group[x] == color) return false;
		}
	}
	return true;
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

	bool possible = true;

	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i] == 0)
		{
			bool res = dfs(i, 1);
			if (!res) {
				cout << "IMPOSSIBLE" << endl;
				possible = false;
				break;
			}
		}
	}
    if (possible) {
		for (int i = 1; i <= n; ++i) {
			cout << group[i] << " ";
		}
	}
	cout << endl;

    return 0; 
}