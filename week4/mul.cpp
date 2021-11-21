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
    pq <ll, vector<ll> > maxq;
    int i = 0;
    while (i < N) {
        ll num;
        cin >> num;
        maxq.push(num);
        if (i < 2) {
            cout << -1 << endl;
        } else {
            vector <ll> top3; 
            for (int j = 0; j < 3; ++j) {
                ll v = maxq.top();
                top3.push_back(v);
                maxq.pop();
            }
            cout << top3[0] * top3[1] * top3[2] << endl;
            for (const auto & v: top3) {
                maxq.push(v);
            }
        }
        ++i;
    }
    
    return 0; 
}