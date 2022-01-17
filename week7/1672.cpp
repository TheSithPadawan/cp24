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
https://cses.fi/problemset/task/1672
Algo:
all sources shortest path using Floyd Warshalls algo
complexity: O(v^3)
for each matrix cell operate n relaxation. There are
v^2 matrix cells
*/

vector <vector<int>> g;
int n, m, q;


void optimize()
{
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                 if (g[i][k] == LLONG_MAX || g[k][j] == LLONG_MAX) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
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

	cin >> n >> m >> q;
    g.resize(n+1);
    for (int i = 0; i <= n; ++i) {
        g[i].resize(n+1);
        fill(g[i].begin(), g[i].end(), LLONG_MAX);
    }

	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
        g[a][b] = min(c, g[a][b]);
        g[b][a] = min(c, g[b][a]);
	}
    
    for (int i = 1; i <= n; ++i) {
        g[i][i] = 0;
    }

    optimize();

	for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (g[a][b] == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << g[a][b] << endl;
        }
    }
    return 0; 
}