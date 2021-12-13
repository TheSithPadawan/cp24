#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

const int M = 2e5 + 5;
vector<int>v[M];
vector<int>vis(M);
vector <int> par (M);


// https://cses.fi/problemset/task/1667

// Algo
// BFS + trace route

void bfs(int node, int n)
{
	vis[node] = 1;

	queue<pair <int, int>>Q;
	Q.push({node, 0});
	bool found = false;
	
	while(!Q.empty())
	{
		auto [cur, dist] = Q.front();
		Q.pop();
		if (cur == n) {
			cout << dist + 1 << endl;
			found = true;
			break; 
		}
		for(auto x : v[cur])
		{
			if(vis[x] == 0)
			{
				vis[x] = 1;
				Q.push({x, dist+1});
				par[x] = cur;
			}
		}
	}

	if (!found) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	// trace route 
	stack <int> route;
	int start = n;
	route.push(start);
	while (start != node) {
		route.push(par[start]);
		start = par[start];
	}

	while (!route.empty()) {
		cout << route.top() << " ";
		route.pop();
	}
	cout << endl;
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

	bfs (1, n);
    
    return 0; 
}