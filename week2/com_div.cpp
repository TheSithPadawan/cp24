/*
cses problem set
common divisor

common factors
3: 3

9: 3 * 3

Input: 3, 14, 15, 7, 9
counts:
3: (3: 1)
14: (2: 1, 7: 1)
15: (3: 1, 5: 1) ==> ans = 3 * 1 ==> update counts (3: 1, 5: 1)
7: (7: 1) ==> ans = 7 * 1 = 7
9: (3: 2) ==> ans = 3 
*/

#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
#define MAX 1e6
 
 
#define endl  "\n"
using namespace std; 
 
vector <int> lp (MAX+1, -1);
vector <int> counts (MAX+1, 0);

void get_factors(int n, um <int, int> & res) {
     while (n > 1) {
         if (lp[n] == -1) {
             res[n]++;
         } else {
             res[lp[n]]++;
         }
        n /= lp[n];
     }
 }
 
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    for (int i = 2; i*i <= MAX; ++i) {
        if (lp[i] == -1) {
            for (int j = i*i; j <= MAX; j += i) {
                lp[j] = i;
            }
        }
    }
    int N;
    // cout << "input N" << endl;
    cin >> N;
    double ans = 1;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        um <int, int> ump;
        get_factors(num, ump);
        double temp = 1;
        for (const auto [k, v]: ump) {
            if (counts[k] > 0) {
                double x = min(v, counts[k]);
                temp = temp * pow( (double) k, x);
            }
            cout << "k: " << k << " v: " << v << endl;
            // update counts
            counts[k] = max(counts[k], v);
            cout << temp << endl;
        }
        // update answer
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0; 
}