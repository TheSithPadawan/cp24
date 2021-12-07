#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// https://cses.fi/problemset/task/1666

/*
Algo: 
	label each connected component from 0 -> N
	The answer is to build k-1 routes if there exists k connected components (CC)
	pick any node from each connected component and output result
*/

const int M = 2e5 + 5;
vector <int>v[M];
vector <int> vis(M);

void dfs(int node)
{
	//visiting this position
	if (vis[node] == 1) return;
	vis[node] = 1;

	for (const int nei: v[node]) {
		if (!vis[nei]){
			dfs(nei);
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
	vector<int> cc;
	for(int i = 1 ; i <= n ; i++)
	{
		if(vis[i] == 0)
		{
			dfs(i);
			cc.push_back(i);
			cnt++;
		}
	}

	cout << cc.size() - 1 << endl;
	for (int i = 0; i < cc.size() - 1; ++i) {
		int cur = cc[i];
		int next = cc[i+1];
		cout << cur << " " << next << endl;
	}
    
    return 0; 
}