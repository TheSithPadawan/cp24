#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
 // monotonic increasing stack
 void find_smaller_right (const vector <int> & nums, vector <int> & res) {
     stack <int> st;
     for (int i = 0; i < nums.size(); ++i) {
         while (!st.empty() && nums[i] < nums[st.top()]) {
             res[ st.top()] = i;
             st.pop();
         }
         st.push(i);
     }
     // smallest element will remain on stack 
    // set its result to be -1
    while (!st.empty()) {
        res[st.top()] = -1;
        st.pop();
    }
 }

 void find_smaller_left(const vector <int> & nums, vector <int> & res) {
     stack <int> st;
     for (int i = nums.size()-1; i >= 0; --i) {
         while (!st.empty() && nums[st.top()] > nums[i]) {
             int index = st.top();
             res[index] = i;
             st.pop();
         }
         st.push(i);
     }
     // smallest element will remain on stack 
    // set its result to be -1
    while (!st.empty()) {
        res[st.top()] = -1;
        st.pop();
    }
 }

 void compute_prefix(const vector <int> & nums, vector <int> & prefix) {
     for (int i = 1; i <= prefix.size(); ++i) {
         prefix[i] = prefix[i-1] + nums[i-1];
     }
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
    vector <int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    vector <int> left (N);
    vector <int> right (N);
    vector <int> prefix(N+1);
    find_smaller_left(arr, left);
    find_smaller_right(arr, right);
    compute_prefix(arr, prefix);
    
    int ans = 0;
    // iterate to update answer
    for (int i = 0; i < N; ++i) {
        int l = (left[i] == -1) ? 0 : left[i]+1;
        int r = (right[i] == -1) ? N-1 : right[i]-1;
        // subarray sum * min value
        int cur = (prefix[r+1] - prefix[l]) * arr[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0; 
}