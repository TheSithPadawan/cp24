#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

class Compare
{
public:
    bool operator() (pair<int, ll> a, pair <int, ll> b)
    {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    
    return 0; 
}