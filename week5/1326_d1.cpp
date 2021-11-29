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
int anslen = 0;
string out = "";

vector <ll> pref(mx); // prefixes of string
vector <ll> revpref(mx);
vector <ll>  pw (mx); // powers of base

void preCal() {
    // compute the power of base
    pw[0] = 1;
    pw[1] = base;
    for (int i = 2; i <= mx; ++i) {
        pw[i] = (pw[i-1] * base)  % mod;
    }
}

void build (const string & s, const string & rs) {
    // compute the prefix hash array of string s
    pref[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); ++i) {
        pref[i] = (pref[i-1] * base + (s[i] - 'a' + 1)) % mod;
    }
    revpref[0] = rs[0] - 'a' + 1;
    for (int i = 1; i < rs.size(); ++i) {
        revpref[i] = (revpref[i-1] * base + (rs[i] - 'a' + 1)) % mod;
    }
}

int getHash (int i, int j, const vector<ll> & res) {
    // returns the hash value of substring of s from i to j inclusive 
    ll ans = res[j];
    if (i-1 >= 0) {
        ans -= (res[i-1] * pw[j-i+1]) % mod;
    }
    if (ans < 0) {
        ans += mod;
    }  
    return (int) ans % mod;
}



void solve (const string & s, const string & rs) {
    int len = s.length();
    for (int i = 0; 2 * i <= len; ++i) {
        if(i == 0) {
            // get longest prefix from middle string
            for (int j = i; j < len-i; ++j) {
                if (getHash(i, j, pref) == getHash (len-j-1, len-i-1, revpref)) {
                    if (j-i+1 + 2*i > anslen) {
                        anslen = j-i+1;
                        out = s.substr(i, anslen);
                        // cout << "update answer to mid str prefix " << out << endl;
                    }
                }
            }

            // get longest suffix from middle string
            for (int j = len-i-1; j >= i; --j) {
                if (getHash(j, len-i-1, pref) == getHash(i, len-j-1, revpref)) {
                    if (len-i-j + 2*i > anslen) {
                        anslen = len-i-j;
                        out = s.substr(j, anslen);
                        // cout << "update answer to mid str suffix " << out << endl;
                    }
                }
            }
        } else {
            if (pref[i-1] == revpref[i-1]) {
                // get longest palindrome prefix from middle string
                for (int j = i; j < len-i; ++j) {
                    if (getHash(i, j, pref) == getHash (len-j-1, len-i-1, revpref)) {
                        if (j-i+1 + 2*i > anslen) {
                            anslen = j-i+1 + 2 * i;
                            // cout << "left: " << s.substr(0, i) << endl;
                            // cout << "mid prefix: " << s.substr(i, j-i+1) << endl;
                            // cout << "right: " << s.substr(len-i, i) << endl;
                            out = s.substr(0, i) + s.substr(i, j-i+1) +  s.substr(len-i, i);
                            // cout << "update answer to " << out << endl;
                        }
                    }
                }

                // get longest palindrom suffix from middle string
                for (int j = len-i-1; j >= i; --j) {
                    if (getHash(j, len-i-1, pref) == getHash(i, len-j-1, revpref)) {
                        if (len-i-j + 2*i > anslen) {
                            anslen = j-i+1 + 2 * i;
                            // cout << "left: " << s.substr(0, i) << endl;
                            // cout << "mid suffix: " << s.substr(j, len-i-j) << endl;
                            // cout << "right: " << s.substr(len-i, i) << endl;
                            out = s.substr(0, i) + s.substr(j, len-i-j) +  s.substr(len-i, i);
                            // cout << "update answer to " << out << endl;
                        }
                    }
                }
            }
        }
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
    int T;
    cin >> T;
    preCal();
    while (T) {
        string s;
        cin >> s;
        pref.clear();
        revpref.clear();
        anslen = 0;
        out = "";
        string rs (s);
        reverse(rs.begin(), rs.end());
        build(s, rs);
        solve(s, rs);
        T--;
    }
    
    return 0; 
}