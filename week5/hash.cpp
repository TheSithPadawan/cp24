#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

const int mx = 1e6+1;
const int base = 31;
const int mod = 1e9+1;

vector <ll> pref(mx); // prefixes of string
vector <ll>  pw (mx); // powers of base

void preCal() {
    // compute the power of base
    pw[0] = 1;
    pw[1] = base;
    for (int i = 2; i <= mx; ++i) {
        pw[i] = (pw[i-1] * base)  % mod;
    }
}

void build (const string & s) {
    // compute the prefix hash array of string s
    pref[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); ++i) {
        pref[i] = (pref[i-1] * base + (s[i] - 'a' + 1)) % mod;
    }
}

int getHash (int i, int j) {
    // returns the hash value of substring of s from i to j inclusive 
    ll ans = pref[j];
    if (i-1 >= 0) {
        ans = ans - (pref[i-1] * pw[j-i+1]) % mod;
    }
    if (ans < 0) {
        ans += mod;
    }  
    return ans;
}

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    string s = "babad";
    preCal();
    build(s);
    cout << getHash(1,1) << " " << getHash(3,3) << endl;
    
    return 0; 
}