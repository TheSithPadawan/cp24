#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
#define ms multiset
 
 
 
#define endl  "\n"
using namespace std; 
 

bool check (const vector <int> & v, int x, int k, int flag) {
    int len = 0;
    int i = 0;
    for (; i < v.size(); ++i) {
        if (!flag) {
            // the other sequence, just add
            len++;
            flag ^= 1;
        } else {
            // add qualifying number to current sequence
            if (v[i] <= x) {
                len++;
                flag ^= 1;
            }
        }
    }
    return len >= k;
}
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> v (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int l = 0, r = 1e9;
    int ans = INT_MAX;
    while (l <= r) {
        int mid =  (l+r)/ 2;
        if (check(v, mid, k, 0) || check (v, mid, k, 1)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0; 
}