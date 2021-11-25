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
const int mod = 1e9+7;

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
        // ans = ans - (pref[i-1] * pw[j-i+1]) % mod;
        ans -= (pref[i-1] * pw[j-i+1]) % mod;
    }
    // cout << "ans " << ans << endl;
    if (ans < 0) {
        ans += mod;
    }  
    return (int) ans % mod;
}

void solve (const string & s, const string & t) {
    // check the number of times t appears in s in O(n) time
    int tsize = t.length();
    // compute hash value of t
    ll thash = t[0] - 'a' + 1;
    for (int i = 1; i < t.size(); ++i) {
        thash = (thash * base + (t[i] - 'a' + 1)) % mod;
    }
    int cnt = 0;
    vector <int> indices;
    for (int i = 0; i < s.length(); ++i) {
        int j = i+tsize-1;
        if (j < s.length()) {
            int hash = getHash(i, j);
            if (hash == thash) {
                cnt++;
                // output index is 1-based
                indices.push_back(i+1);
            }
        }
    }
    if (cnt != 0) {
        cout << cnt << endl;
        for (int i = 0; i < indices.size(); ++i) {
            cout << indices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Not Found" << endl;
    }
    cout << endl;

}

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int T = 0;
    cin >> T;
    preCal();
    while (T) {
        string s, t;
        cin >> s >> t;
        pref.clear();
        build(s);
        solve(s, t);
        T--;
    }
    
    return 0; 
}