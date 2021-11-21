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

 

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int N;
    cin >> N;
    ms <ll> s;
    for (int i = 0; i < N; ++i) {
        ll num;
        cin >> num;
        s.insert(num);
    }
    // cout << "here" << endl;
    while (1) {
        if (s.empty()) {
            cout << "YES" << endl;
            break;
        }
        if (s.size() == 1) {
            cout << "NO" << endl;
            break;
        }
        ll mx = *s.rbegin();
        s.erase(s.equal_range(mx).first);
        ll mn = *s.begin();
        s.erase(s.equal_range(mn).first);
        ll mxpost = mx-1;
        ll mnpost = mn-1;
        if (mxpost != 0){
            s.insert(mxpost);
        }
        if (mnpost != 0) {
            s.insert(mnpost);
        }
        // cout << "after current operation" << endl;
        // for (const auto v: s) {
        //     cout << v << endl;
        // } 
    }
    
    return 0; 
}