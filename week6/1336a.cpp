#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// https://codeforces.com/problemset/problem/1336/A 




// global variables
const int mx = 2e5 + 5;
vector <ll> v[mx];
vector <ll> depths(mx);
vector<ll>subtreeSize(mx);

void dfs(int node, int par)
{
    // height is the height of parent not counting current node
    depths[node] = depths[par] + 1;
	for(auto x : v[node])
	{
        if (x == par)
            continue;
		dfs(x , node);
        subtreeSize[node] += subtreeSize[x];
	}
    subtreeSize[node]++;
}


void solve()
{
	//first clear global variables

	int n , k;
	cin >> n >> k;
    k = n-k;

	for(int i = 0 ; i < n - 1 ; i++)
	{
		ll a , b;
		cin >> a >> b;
		v[a].push_back(b);
        v[b].push_back(a);
	}


	depths[0] = -1;
    dfs(1, 0);
    vector <ll> changes;

    for (int i = 1; i <= n; ++i) {
        ll c = subtreeSize[i] - 1 - depths[i];
        changes.push_back(c);
    }
    sort(changes.begin(), changes.end(), greater<ll>());
    //let's take first k elements of tourism cities and aggregate the changes
    ll happiness = 0;
    for (int i = 0; i < k; ++i) {
        happiness += changes[i];
    }
	cout << happiness << endl;
}

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int t;
	t = 1;
	while(t--)
		solve();
    
    return 0; 
}