#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define md 998244353
 
 // Lc problem: https://leetcode.com/problems/longest-palindromic-substring/submissions/
 
 
#define endl  "\n"
using namespace std; 

const int mx = 1e6+1;
const int base = 31;
const int mod = 1e9+1;
int maxlen = 0;
string out;

vector <ll>  pw (mx); // powers of base

void preCal() {
    // compute the power of base
    pw[0] = 1;
    pw[1] = base;
    for (int i = 2; i <= mx; ++i) {
        pw[i] = (pw[i-1] * base)  % mod;
    }
}

vector <ll> build (const string & s) {
    // compute the prefix hash array of string s
    vector <ll> pref(mx); // prefixes of string
    pref[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); ++i) {
        pref[i] = (pref[i-1] * base + (s[i] - 'a' + 1)) % mod;
    }
    return pref;
}

int getHash (int i, int j, const vector <ll> & pref) {
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

int get_reverse(int N, int num) {
    // compute the index of the reverse string
    return N-1-num;
}

void solve (const string & s) {
    // O(nlgn) solution
    // to do: O(n) solution Manacher's algo 
    string rs (s.rbegin(), s.rend());
    vector <ll> prefix = build(s);
    vector <ll> rev = build(rs);

    int N = s.length();

    // expand from center, substring length = 2*L+1 odd
    for (int i = 1; i < N; ++i) {
        int l = 0;
        int r = min(i+1, N - i-1);
        while (l <= r) {
            int mid = (l+r) / 2;
            cout << "mid = " << mid << endl;
            int start = i-mid;
            int end = i+mid;
            if (getHash(start, i-1, prefix) == getHash(N-end-1, N-(i+1)-1, rev)) {
                // found, update actual string length
                if (end-start+1 > maxlen) {
                    cout << "i = " << i << endl;
                    cout << "max len = " << mid << endl;
                    cout << "start index " << start << endl;
                    maxlen = end-start+1;
                    out = s.substr(start, end-start+1);
                }
                l = mid + 1;
            } else {
                r = mid -1;
            }
         }
    }

    // repeat for even, assume current index i is at the left center
    // now we consider all pairs (i, i+1)
    for (int i = 0; i < N-1; ++i) {
        // the center pair must be equal
        if (s[i] != s[i+1]) continue;
        cout << "considering evens i = " << i << endl;
        int l = 0;
        int r = min(i+1, N-i-2);
        while (l <= r) {
            int mid = (l+r) / 2;
            cout << "mid: " << mid << endl;
            int start = i - mid;
            int end = i+1 + mid;
            if (getHash(start, i-1, prefix) == getHash(get_reverse(N, end), get_reverse(N, i+2), rev)) {
                // found, actual string length = end - start + 1
                if (end-start+1 > maxlen) {
                    cout << "i = " << i << endl;
                    cout << "max len = " << mid << endl;
                    cout << "start index " << start << endl;
                    maxlen = end-start+1;
                    out = s.substr(start, maxlen);
                }
                l = mid+1;
            }else {
                r = mid-1;
            }
        }
    }
    
    // cout << check(s, prefix, rs, rev, 5, 0, 4) << endl;
    if (out.length() > 0){
        cout << out << endl;
    } else {
        // no ans just return the first char
        cout << s[0] << endl;
    }
}

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int t = 1;
    preCal();
    while (t) {
        string s;
        cin >> s;
        solve(s);
        t--;
    } 
    return 0; 
}