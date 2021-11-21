#include<bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
void init_diff_array(const vector <int> & nums, vector <int> & diff) {
    int n = nums.size();
    diff[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        diff[i] = nums[i] - nums[i-1];
    }
}

void update(int l, int r, int x, vector <int> & diff) {
    diff[l] += x;
    cout << "r+1: " << r+1 << endl; 
    diff[r+1] -= x;
}

void get_value (vector <int> & nums, vector <int> & diff) {
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            nums[i] = diff[i];
        } else {
            nums[i] = nums[i-1] + diff[i];
        }
    }
}
 
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, q;
    cin >> n >> m >> u >> q;
    vector <vector<int>> v(n, vector<int>(m));
    
     // initialize diff matrix
    vector <vector<int>> diff (n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
        // completed one row, initialize differential vector for this row
        init_diff_array(v[i], diff[i]);
    }
   
    for (int i = 0; i < u; ++i) {
        int k, r1, c1, r2, c2;
        cin >> k >> r1 >> c1 >> r2 >> c2;
        for (int j = r1; j <= r2; ++j) {
            update(c1, c2, k, diff[j]);
        }
    }

    // get updated results 
    for (int i = 0; i < n; ++i) {
        get_value(v[i], diff[i]);
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // construct dp array 
    vector <vector<ll>> dp (n, vector<ll>(m));
    // first row 
    dp[0][0] = v[0][0];
    for (int j = 1; j < m; ++j) {
        dp[0][j] = v[0][j] + dp[0][j-1];
    }
    // first col 
    for (int i = 1; i < n; ++i) {
        dp[i][0] = v[i][0] + dp[i-1][0];
    }
    // store other info
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + v[i][j];
        }
    }
    
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // answer query 
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        ll result = dp[r2][c2];
        if (r1-1 >= 0) {
            result -= dp[r1-1][c2];
        }
        if (c1-1 >= 0) {
            result -= dp[r2][c1-1];
        }
        if (r1-1 >= 0 && c1-1 >= 0) {
            result += dp[r1-1][c1-1];
        }
        cout << result << endl;
    }
    return 0; 
}