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

void dfs(int node)
{
	//visiting this node

	vis[node] = 1;

	for(auto x : v[node])
	{
		if(vis[x] == 0)
			dfs(x);
	}
}

void bfs(int node)
{
	vis[node] = 1;

	queue<int>Q;
	Q.push(node);

	while(!Q.empty())
	{
		int curr = Q.front();
		Q.pop();
		//visit the breadth of this element

		for(auto x : v[curr])
		{
			if(vis[x] == 0)
			{
				vis[x] = 1;
				Q.push(x);
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

    int n , m;
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	int cnt = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i] == 0)
		{
			cnt++;
			dfs(i);
		//	bfs(i);
		}
	}

	cout << cnt << endl;
    
    return 0; 
}