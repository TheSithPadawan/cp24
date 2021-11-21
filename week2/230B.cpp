#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 
 
/*
Algo: t prime is a number that is the square of a prime
*/
 
 
int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    vector <bool> is_prime(1e6+1, true);
    for (int i = 2; i*i <= 1e6; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                is_prime[j] = false;
            }
        }
    }
  
    um <ll, bool> tprimes;
    for (int i = 2; i <= 1e6; ++i) {
        if (is_prime[i]) {
            ll index = (ll) i * i;
            tprimes[index] = true;
        }
    }
    int N;
    cin >> N;
    while (N) {
        ll num; 
        cin >> num;
        if (tprimes.find(num) == tprimes.end()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        N--;
    }
    return 0; 
}