#include <iostream>
#include <vector>

using namespace std;

bool check (int A, const vector <int> & C, int t) {
    /*
    check that given time allocated per person and C,
    the number of persons needed to complete the task
    t: time per person  
    */
    int persons = 1;
    int i = 0;
    int x = t;
    while ( i < C.size()) {
        if (persons > A) return false;
        if (C[i] <= x) {
            x -= C[i];
            i++;
        } else {
            persons++;
            x = t;
        }
    }
    return persons <= A;
}


int paint(int A, int B, vector<int> &C) {
    long long l = 0;
    long long total = 0;
    for (const int x: C) {
        // todo: modulo operations
        total = total % 10000003 + x % 10000003;
    }
    long long r = total * B;
    long long ans = 0;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (check(A, C, mid/B)) {
            ans = mid % 10000003;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector <int> test = {640, 435, 647, 352, 8, 90, 960, 329, 859};
    int A = 3;
    int B = 10;
    cout << paint(A, B, test) << endl; 
    return 0;
}