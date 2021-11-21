#include <iostream>
#include <vector>

using namespace std;


bool check (const vector <int> & a, const vector <int> & b, long long t) {
    /*
    if delivery is within the time limit t, choose delivery
    otherwise choose pickup. check passes if total time <= time limit t
    */
   long long res = 0;
   long long cur = 0;
   int n = a.size();
   for (int i = 0; i < n; ++i) {
       if (a[i] <= t) {
           res = max(res, (long long) a[i]);
       } else {
           res = max(res, cur + b[i]);
           cur += b[i];
       }
   }
    return res <= t;
}

int solve (const vector <int> & a, const vector <int> & b, long long r) {
    long long l = 0;
    long long ans = 0;
    while (l <= r) {
        long long mid = l + (r-l) / 2;
        if (check(a, b, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main () {
    int t, N, C;
    cin >> t;
    long long max1 = 0, max2 = 0;
    while (t--) {
        cin >> N;
        vector <int> a;
        vector <int> b;
        // fill delivery vector
        for (int i = 0; i < N; ++i) {
            int num = 0;
            cin >> num;
            max1 = max(max1, (long long) num);
            a.push_back(num);
        }
        // fill pickup vector
        for (int i = 0; i < N; ++i) {
            int num = 0;
            cin >> num;
            max2 += num;
            b.push_back(num);
        }
        cout << solve(a, b, min(max1, max2)) << endl;
    }
    return 0;

}
