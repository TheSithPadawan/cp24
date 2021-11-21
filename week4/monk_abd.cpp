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
    int N;
    cin >> N;
    vector <int> vec (N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int num;
    cin >> num;
    while (num) {
        int k;
        char op;
        cin >> k >> op;
        cout << "k = " << k << " op = " << op << endl;
        if (op == 'L') {
            int pos = N - k;
            cout << vec[pos] << endl;
        } else {
            int pos = k-1;
            cout << vec[pos] << endl;
        }
        num--;
    }
    return 0; 
}