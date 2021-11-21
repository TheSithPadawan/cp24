#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
int counts = 0;

// let's do it in place
// merge sort template
void merge_sort (vector <int> & nums, int start, int end, vector <int> & out) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(nums, start, mid, out);
    merge_sort(nums, mid+1, end, out);

    int l = start, r = mid+1;
    // before merge let's do the counting step
    while (l <= mid && r <= end) {
        
        if (nums[l] > 2 * nums[r]) {
            counts += mid-l+1;
            r++;

        } else {
            l++;
        }
    }

    out.clear();
    l = start, r = mid+1;
    while (l <= mid && r <= end) {
        if (nums[l] < nums[r]) {
            out.push_back(nums[l]);
            l++;
        }else {
            out.push_back(nums[r]);
            r++;
        }
    }
    while (l <= mid) {
        out.push_back(nums[l]);
        l++;
    }
    while (r <= end) {
        out.push_back(nums[r]);
        r++;
    }
   
    for (int idx = 0; idx < out.size(); idx++) {
        nums[start+idx] = out[idx];
    }
}
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    vector <int> nums {1,3,2,3,1};
    vector <int> out;
    merge_sort(nums, 0, nums.size()-1, out);
    cout << counts << endl;
    return 0; 
}