#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
 
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int T, L, R;
    cin >> T;
    vector <int> prefix (1e5+2);
    for (int i = 1; i <= 1e5+1; ++i) {
        if (i % 10 == 2 || i % 10 == 3 || i % 10 == 9) {
            prefix[i] = prefix[i-1] + 1;
        } else {
            prefix[i] = prefix[i-1];
        }
    }
    while (T) {
        cin >> L >> R;
        cout << prefix[R] - prefix[L-1] << endl;
        T--;
    }
     return 0; 
}