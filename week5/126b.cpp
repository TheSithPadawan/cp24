#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// problem: https://codeforces.com/contest/126/problem/B
/*
Algo:
for each prefix and suffix of varying length, store it in an array
use binary search to check if this length also can be found in the
middle string.
*/

const int mx = 1e6+1;
const int base = 31;
const int mod = 1e9+7;
int ans = 0;
string out = "";

vector <ll> pref(mx+1); // prefixes of string
vector <ll>  pw (mx+1); // powers of base

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
        ans -= (pref[i-1] * pw[j-i+1]) % mod;
    }
    if (ans < 0) {
        ans += mod;
    }  
    return (int) ans % mod;
}

bool check (const string & s, int len) {
    ll prefix_hash = getHash(0, len-1);
    for (int j = 1; j < s.length() - 1; ++j) {
        if (j + len - 1 < s.length() - 1) {
            if (getHash(j, j+len-1) == prefix_hash) return true;
        }
    }
    return false;
}

void solve (const string & s) {

    vector <ll> lens;
    for (int i = 0; i <= s.length(); ++i) {
        ll prefix_hash = getHash(0, i-1);
        ll postfix_hash = getHash(s.length() - i, s.length() - 1);
        if (prefix_hash == postfix_hash) {
            lens.push_back(i);
        }
    }
    // lens is increasing monotonically now
    ll l = 0, r = lens.size()-1;
    
    while (l <= r) {
        ll mid_index = (l+r) / 2;
        ll mid = lens[mid_index];
        if (check(s, mid)) {
            ans = mid;
            out = s.substr(0, mid);
            l = mid_index + 1;
        } else {
            r = mid_index - 1;
        }
    }
   if (ans == 0) {
       cout << "Just a legend" << endl;
       return;
   }
   cout << out << endl;
}

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    preCal();
    
    string s;
    cin >> s;
    pref.clear();
    build(s);
    solve(s);
    // cout << check(s, s.length()) << endl;
    return 0; 
}