#include <bits/stdc++.h>
#define ll long long
#define  um unordered_map
#define us unordered_set
#define pq priority_queue
#define mod 1000000007
#define md 998244353
 
 
 
#define endl  "\n"
using namespace std; 

// um <string, int> cache;

int replace_cost(const string & s, char c) {
    int cost = 0;
    for (const auto ch: s) {
        if (ch != c) cost++;
    }
    return cost;
} 

int get_cost (string s, char c) {
    if (s.length() == 1) {
        return (s[0] == c) ? 0 : 1;
    }
    // if (cache.find(s) != cache.end()) {
    //     return cache[s];
    // }
    char next = (int) c + 1;
    int res1 = replace_cost(s.substr(0, s.length()/2), c);
    int res2 = get_cost(s.substr(s.length()/2), next);
    int res3 = get_cost(s.substr(0, s.length()/2), next);
    int res4 = replace_cost(s.substr(s.length()/2), c);
    // return cache[s] = min(res1+res2, res3+res4);
    return min(res1+res2, res3+res4);
}

int main()
{
    // allows c++ to has its own buffer
    // faster in some cases
    ios_base::sync_with_stdio(0);
    // untie cin and cout; thus need to flush cout manually
    cin.tie(0);
    int t;
    cin >> t;
    while (t) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << get_cost(s, 'a') << endl;
        t--;
    }
    return 0; 
}   