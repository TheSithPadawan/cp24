#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

um <ll, ll> seats;
 
struct Comp {
  bool operator () (const pair <ll, ll> & a, const pair <ll, ll> & b) {
    ll sizea = a.second - a.first;
    ll sizeb = b.second - b.first;
    if (sizea == sizeb) {
        return a.first > b.first;
    }
    return sizea < sizeb;
  }
};
 
void assign(int N, int K, priority_queue <pair <ll, ll>, vector <pair<ll, ll>>, Comp> & maxq, const string & s) {
    maxq.push({1, N});
    for (ll i = 1; i <= K; ++i) {
        if (!maxq.empty()) {
            auto [x, y] = maxq.top();
            maxq.pop();
            ll mid = (x+y) / 2;
            if ((y - x+1) % 2 == 0) {
                char p = s[i-1];
                if (p == 'L') {
                    seats[mid] = i;
                    if (mid-1 >= x) {
                    maxq.push({x, mid-1});
                    }
                    if (y >= mid+1) {
                        maxq.push({mid+1, y});
                    }
                } else {
                    seats[mid+1] = i;
                    maxq.push({x, mid});
                    if (y >= mid+2) {
                        maxq.push({mid+2, y});
                    }
                }
            } else {
                seats[mid] = i;
                if (mid-1 >= x) {
                    maxq.push({x, mid-1});
                }
                if (y >= mid+1) {
                    maxq.push({mid+1, y});
                }
            }
        }
    }
}

int main()
{
    // allows c++ to has its own buffer
    // faster in some 36
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    string pref;
    cin >> pref;
    ll qs;
    cin >> qs;
    pq <pair <ll, ll>, vector <pair<ll, ll>>, Comp> maxq;
    assign(N, K, maxq, pref);
    while (qs) {
        ll i;
        cin >> i;
        if (seats.find(i) != seats.end()) {
            cout << seats[i] << endl;
        } else {
            cout << -1 << endl;
        }
        qs--;
    }
    return 0; 
}