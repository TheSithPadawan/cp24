#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// https://cses.fi/problemset/task/1192
/*
Algo:
	At each floor, perform dfs 
	Just return the total # of dfs performed in the graph
*/

const int mx = 1000;
vector<vector<char>> v (mx, vector<char>(mx));
// vector<vector<int>>vis(mx, vector<int>);

void dfs(int x, int y, int n, int m)
{
	//visiting this position
	if (v[x][y] == '#') return;
	v[x][y] = '#';

	vector <int> dx = {1, 0, -1, 0};
	vector <int> dy = {0, -1, 0, 1};
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		dfs(nx, ny, n, m);
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

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '.'){
				dfs(i, j, n, m);
				cnt++;
			}
		}
	}
    
	cout << cnt << endl;
    return 0; 
}