#include <iostream>
#include <vector>

using namespace std;

bool check (int c, int dist, const vector <int> & stalls) {
    /*
    checks if current configuration is valid:
    can we assign all cows to stalls with current distance
    */
   int cowCnt = 0, reqDist = 0;
   for (const int s: stalls) {
       if (s >= reqDist) {
           cowCnt++;
           reqDist = s + dist;
       }
       if (cowCnt >= c) return true;
   }
   return false;
}

int solve (int N, int c, const vector <int> & stalls) {
    long long l = 0, r = stalls[stalls.size()-1];
    // binary search here
    long long ans = 0;
    while (l <= r) {
        int mid = l + (r-l) / 2;
        if (check(c, mid, stalls)) {
            // update answer 
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main () {
    int t, N, C;
    cin >> t;
    while (t--) {
        cin >> N >> C;
        vector <int> stalls;
        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            stalls.push_back(val);
        }
        sort(stalls.begin(), stalls.end());
        cout << solve(N, C, stalls) << endl;
    }
    return 0;

}
