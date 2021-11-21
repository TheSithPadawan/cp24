#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
void solve(string line) {
    stack <pair<char, int>> st;
    int i = 0;
    while (i < line.size()) {
        if (line[i] == '0') {
            if (!st.empty() && st.top().first == '*') {
                // some processing
                if (st.top().second > 0) {
                    st.top().second -= 1;
                    if (st.top().second == 0){
                        st.pop();
                    }
                } else {
                    st.push(make_pair('0', -1));
                }
            } else {
                st.push(make_pair('0', -1));
            }
        } else {
            st.push(make_pair('*', 2));
        }
        ++i;
    }
    if (st.empty()) {
        cout << "YES" << endl;
        return;
    } 
    while (!st.empty()) {
        auto res = st.top();
        auto x = res.first;
        if (x == '0') {
            cout << "NO" << endl;
            return;
        }
        st.pop();
    }
    cout << "YES" << endl;
}
 
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
        string line;
        cin >> line;
        solve (line);
        t--;
    }
    return 0;
}