#include <bits/stdc++.h>
#include<numeric>  // c++ 17 __gcd(a, b)
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 #define MAX 200011
 
 
#define endl  "\n"
using namespace std; 
 
 /*
Algo: 
first compute frequency of factors of all input numbers in range 1 - 2*1e5 (sqrt(N))
Then compute LCM (p, q)
answer = d[p] + d[q] + d[LCM(p, q)]
use gcd to compute LCM
 */

vector <int> d(MAX+1, 0);

// factorization
void find_divisor(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (i*i == n) {
            d[i]++;
        } else if (n % i == 0) {
            d[i]++;
            d[n/i]++;
        }
    }
}
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int N, T;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        find_divisor(v);
    }
    cin >> T;
    while (T) {
        int p, q;
        cin >> p >> q;
        if (p > q) {
            swap(p, q);
        }
        int gcdr = gcd(p, q);
        int lcm = p * q / gcdr;
        int count = (lcm > 200000) ? 0 ; d[lcm];
        cout << d[p] + d[q] - count << endl;
        T--;
    }
    return 0; 
}