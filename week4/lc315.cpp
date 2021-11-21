#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
vector <int> res (3);

int binarySearch(const vector <pair<int, int>> & arr,int l,int r, int k){
   int low = l;
   int high = r;
   int mid = (high+low)/2;
   int index = -1;
   while(low <= high){
      mid =( low + high ) / 2;
      if(arr[mid].first <= k){
         index = mid;
         low = mid+1;
      }
      else{
         high=mid-1;
      }
   }
   if (index == -1) {
       return 0;
   }
   return (index - l + 1);
}

// let's do it in place
// merge sort template
void merge_sort (vector <pair<int, int>> & nums, int start, int end, vector <pair<int, int>> & out) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge_sort(nums, start, mid, out);
    merge_sort(nums, mid+1, end, out);

    int l = start, r = mid+1;
    // before merge let's do the counting step
    while (l <= mid) {
        int count = binarySearch(nums, r, end, nums[l].first-1);
        int index = nums[l].second;
        res[index] += count;
        l++;
    }

    out.clear();
    l = start, r = mid+1;
    while (l <= mid && r <= end) {
        if (nums[l].first < nums[r].first) {
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
    vector <pair<int, int>> nums {{2, 0},{0, 1}, {1, 0}};
    vector <pair<int, int>> out;
    merge_sort(nums, 0, nums.size()-1, out);
    for (const auto & v: res) {
        cout << v << " ";
    }
    cout << endl;
    return 0; 
}