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
https://cses.fi/problemset/task/1194
Algo:
run multi sources bfs from all monsters, record distance in dist
Then use single source bfs from A to find a valid path (if exists)
safe only if for valid points pi, dist(A, pi) < dist(M, pi)
record the parent during bfs from A
finally reconstruct the path and print
*/

const int M = 1001;
int n, m; 
// graph
vector <vector<char>> v(M, vector<char> (M));

vector <vector<int>> dist (M, vector<int> (M, INT_MAX));

vector <int> dx = {1, 0, -1, 0};
vector <int> dy = {0, -1, 0, 1};

set <pair<int, int>> dest;
vector<pair<int,int>> monsters;
// map that is used to record route
map<pair<int,int>, pair<int,int>> par;
// start and end point
pair<int,int> si, se; 


// compute distance of each monster to everywhere else
void process_monster() {
    queue <tuple<int, int, int>> q; 
    for (const auto m: monsters) {
        q.push({m.first, m.second, 0});
    }
    while (!q.empty()) {
        auto [x, y, z] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (v[nx][ny] != '.') continue;
            if (dist[nx][ny] <= z+1) continue;
            dist[nx][ny] = z+1;
            q.push({nx, ny, z+1});
        }
    }
}

bool is_valid(int x, int y, int cur) {
    // the location is only valid for player
    // if no monster can get there before the player
    // and the location is not out of boundary
    // and the location is not a wall or a monster
    if (v[x][y] != '.') return false;
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (dist[x][y] <= cur) return false;
    return true;
}

bool bfs_escape() {
    queue <tuple<int, int, int>> q;
    if (si.first == -1 && si.second == -1) return false;
    q. push({si.first, si.second, 0});
    while (!q.empty()) {
        auto [x, y, z] = q.front();
		q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!is_valid(nx, ny, z+1)) continue;
            // if successfully escape, return True, update endpoint 
            par[{nx, ny}] = {x, y};
            dist[nx][ny] = z+1;
            // if at the border
            if (nx == n-1 || ny == m-1 || nx == 0 || ny == 0) {
                se.first = nx;
                se.second = ny;
                return true;
            }
            q.push({nx, ny, z+1});
        }
    }
    return false;
}

int32_t main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);

	cin >> n >> m;
    si.first = -1;
    si.second = -1;
    // add all monsters to monster
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 'M') {
                monsters.push_back({i, j});
            } else if (v[i][j] == 'A'){
                si.first = i;
                si.second = j;
            }
        }
    }    
    // process monster
    process_monster();
    // edge case  check
    if (si.first == n-1 || si.second == m-1 || si.first == 0 || si.second == 0) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }
    // process player
    bool res = bfs_escape();
    if (res) {
        cout << "YES" << endl;
        cout << dist[se.first][se.second] << endl;
    } else {
        cout << "NO" << endl;
        return 0;
    }

    // print route
    stack <char> dir;
    int tx = se.first;
    int ty = se.second;
    while (tx != si.first || ty != si.second) {
        auto parent = par[{tx, ty}];
        if (parent.first == tx && parent.second < ty) {
            dir.push('R');
        } else if (parent.first == tx && parent.second > ty) {
            dir.push('L');
        } else if (parent.second == ty && parent.first < tx) {
            dir.push('D');
        } else {
            dir.push('U');
        }
        tx = parent.first;
        ty = parent.second;
    }
    while (!dir.empty()) {
        cout << dir.top();
        dir.pop();
    }
    cout << endl;
    return 0; 
}