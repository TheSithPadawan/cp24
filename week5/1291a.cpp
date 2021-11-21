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
    int t;
    cin >> t; 
    while (t) {
        int digits; 
        cin >> digits;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < digits; ++i) {
            if ((s[i] - '0') % 2 != 0) {
                cnt++;
            }
        }
        if (cnt < 2) {
            cout << -1 << endl;
        } else {
            int cnt = 2;
            for (int i = 0; i < digits && cnt > 0; ++i) {
                if ((s[i] - '0') % 2 != 0) {
                    cout << s[i];
                    cnt--;
                }
            }
            cout << endl;
        }
        t--;
    }
    return 0; 
}