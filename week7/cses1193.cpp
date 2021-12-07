#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// https://cses.fi/problemset/task/1193
/*
Algo:
	use bfs start from A, ends at B
	for each position record where it comes from in parent vector 
*/

const int mx = 1000;
vector <vector<char>> v (mx, vector<char>(mx));
vector <vector<int>> vis(mx, vector<int>(mx));
vector <int> dx = {1, 0, -1, 0};
vector <int> dy = {0, -1, 0, 1};
vector <vector<pair<int, int>>> par (mx, vector<pair<int, int>>(mx));

queue <tuple<int, int, int>> Q;
int endx = 0, endy = 0, startx = 0, starty = 0;

int bfs(int n, int m)
{
	while(!Q.empty())
	{
		for (int size = 0; size < Q.size(); ++size) {
			auto [x, y, z] = Q.front();
			Q.pop();
			if (x == endx && y == endy) {
				// done 
				return z;
			}
			for(int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (vis[nx][ny] || v[nx][ny] == '#') continue;
				vis[nx][ny] = 1;
				Q.push({nx, ny, z+1});
				par[nx][ny] = {x, y};
			}
		}
	}
	return -1;
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
			if (v[i][j] == 'A') {
				Q.push({i, j, 0});
				vis[i][j] = 1;
				startx = i;
				starty = j;
			} else if (v[i][j] == 'B') {
				endx = i;
				endy = j;
			}
		}
	}

	int ans = bfs(n, m);
    if (ans == -1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << ans << endl;
	// cout << "check" << endl;
	// cout << par[3][2].first << "," << par[3][2].second << endl;


	stack <char> st;

	int x = endx, y = endy;
	while (x != startx || y != starty) {
		auto [nx, ny] = par[x][y];
		// cout << "prev x: " << nx << " prev y: " << ny << endl;
		if (nx < x) {
			st.push('D');
		} else if (nx > x) {
			st.push('U');
		} else if (ny < y) {
			st.push('R');
		} else if (ny > y) {
			st.push('L');
		}
		x = nx;
		y = ny;
	}
	// output result 
	while (!st.empty()){
		char dir = st.top();
		cout << dir;
		st.pop();
	}
	cout << endl;
    return 0; 
}