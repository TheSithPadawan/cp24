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
    int N;
    cin >> N;
    int maxc = 0;
    vector <int> lp(N+2, -1);
    vector <int> colors(N+2);
    int cur = 1;
    for (int i = 2; i <= N+1; ++i) {
        if (lp[i] == -1) {
            cur = 1;
            colors[i-1] = cur;
            maxc = max(cur, maxc);
            cur++;
            if ( (ll) i * i > N+1) continue;
            for (int j = i * i; j <= N+1; j += i) {
                lp[j] = i; 
                colors[j-1] = cur;
                maxc = max(cur, maxc);
            }
        }
    }
    
    cout << maxc << endl;
    for (int i = 1; i <= N; ++i) {
        cout << colors[i] << ' ';
    }
    cout << endl;
    return 0; 
}