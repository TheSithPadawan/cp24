#include <iostream>
#include <vector>

using namespace std;

/*
Solution for 1433 problem C using sorting
*/

int main () {
    int t, N, C;
    cin >> t;
    long long curmax = 0, ans = 0;
    while (t--) {
        cin >> N;
        vector <pair <long long, long long>> v (N);
        vector <long long> prefix(N+1);
        // fill delivery and pick up
        for (int i = 0; i < N; ++i) {
            int num = 0;
            cin >> v[i].first;
        }
        for (int i = 0; i < N; ++i) {
            int num = 0;
            cin >> v[i].second;
        }
        sort(v.begin(), v.end());
        for (int i = 1; i <= N; ++i) {
            prefix[i] = prefix[i-1] + v[i-1].second;
        }
        // traverse the array 
        ans = prefix[N];
        for (int i = 0; i < N; ++i) {
            // maximum delivery time
            curmax = max(v[i].first, prefix[N] - prefix[i+1]);
            ans = min(ans, curmax);
        }
        cout << ans << endl;
    }
    return 0;

}
