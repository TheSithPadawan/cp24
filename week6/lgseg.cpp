#include <bits/stdc++.h>
#define int long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353

 
#define endl  "\n"
using namespace std; 
const int mx = 1e5 + 5;

const int LOG = 25;
vector <int> par (mx);
int up[mx][LOG];
vector <int> nums(mx);

// https://www.codechef.com/problems/LGSEG

int jump (int e, int k, int n) {
    // jump node e to k levels above
    // in this case returns the new ending index j
    for (int bit = 0; bit < LOG; ++bit) {
        // use 1LL here in case bit left shifting causes integer overflow
        if ((1LL<<bit) & k) {
            // take the jump 
            // last node, no need to lift
            if (e == n) break;
            e = up[e][bit];
        }
    }
    return e;
}

void binary_lifting(int n) {
    // pre-compute up matrix, n is the number of nodes
    for (int i = 0; i < n; ++i) {
        // 2 ^ 0 = 1, it's just the parent
        up[i][0] = par[i];
    }

    for (int p = 1; p < LOG; ++p) {
        for (int i = 0; i < n; ++i) {
            // temp = node i 's previous jump to 2^ (p-1) level
            // we are only storing 2^0 (parent level), 2^1, 2^2 .... , 2^k levels up
            int temp = up[i][p-1];
            if (temp == n) {
                up[i][p] = n;
            } else {
                up[i][p] = up[temp][p-1];
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
    int q; 
    cin >> q;
    
    while (q--) {
        int ans = 0;
        // reset global variables
        // memset(up, 0, sizeof(up[0][0]) * mx * LOG);
        par.clear();
        nums.clear();

        int n, k, s;
        cin >> n >> k >> s;
        vector <int> prefix (n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        // compute prefix sum
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        par[n] = n;
        // compute parent array, the ending index of the first sub segment that qualifies s
        for (int i = 0; i < n; ++i) {
            int prev = 0;
            if (i != 0) prev = prefix[i-1]; 
            // lower bound returns an iterator, to get index need to - vec.begin()
            // par [i] is the index j where [i, j-1] is a qualifying sub-segment
            par[i] = lower_bound(prefix.begin(), prefix.end(), prev+s+1) - prefix.begin();
        }
        
        // binary lifting
        binary_lifting(n);

        // update answer
        for (int i = 0; i < n; ++i) {
            int end = jump(i, k, n);
            ans = max(end-i, ans);
        }
        cout << ans << endl;
    }
    return 0; 
}