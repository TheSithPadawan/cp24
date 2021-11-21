#include<bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
 // O(1) time range query update

void init_diff_array(const vector <int> & nums, vector <int> & diff) {
    int n = nums.size();
    diff[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        diff[i] = nums[i] - nums[i-1];
    }
}

void update(int l, int r, int x, vector <int> & diff) {
    diff[l] += x;
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
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int T, N;
    cin >> T;
    while (T) {
        cin >> N;
        vector <int> C (N);
        vector <int> H (N);
        vector <int> rad (N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> H[i];
        }
        // solve 
        // initialize diff array
        vector <int> diff (N+1);
        init_diff_array(rad, diff);
        // first loop over each value in C, update array 
        for (int i = 0; i < N; ++i) {
            int l = (i - C[i] < 0 ) ? 0 : i - C[i];
            int r = (i + C[i] >= N) ? N-1 : i + C[i];
            update(l, r, 1, diff);
        }
       
        get_value(rad, diff);
        // for (const int x: rad) {
        //     cout << x << " ";
        // }
        // cout << endl;
        
        // sort C 
        sort(rad.begin(), rad.end());
        // sort H
        sort(H.begin(), H.end());
        // compare 
        bool check = true;
        for (int i = 0; i < N; ++i) {
            if (H[i] != rad[i]) {
                cout << "NO" << endl;
                check = false;
                break;
            }
        }
        if (check) {
            cout << "YES" << endl;
        }
        
        T--;
    }
    return 0; 
}