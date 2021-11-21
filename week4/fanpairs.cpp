#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
// 4 3 1
void solve(const vector <int> & arr) {
    int n = arr.size();
    stack <int> st; 
    // left next greater element 
    vector <int> left (arr.size());
    for (int i = arr.size()-1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        left[st.top()] = -1;
        st.pop();
    }

    // right next greater element
    vector <int> right (arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        right[st.top()] = -1;
        st.pop();
    }

    um <ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
        int l = (left[i] == -1) ? -1 : left[i];
        if (right[i] == -1) continue;
        int r = right[i];
        if (cnt.find(r - i) != cnt.end()) {
            // update maximum number of pairs
            cnt[r-i] = max(cnt[r-i], (ll) i - l);
        } else {
            cnt[r-i] = i-l;
        }
    }
    ll ans = 0;
    for (const auto [x, y] : cnt) {
        ans += y;
    }
    cout << ans << endl;
}
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int N;
    cin >> N;
    vector <int> arr (N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    solve(arr);
    return 0; 
}