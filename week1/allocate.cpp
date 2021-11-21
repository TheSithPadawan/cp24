#include <iostream>
#include <vector>

using namespace std;

/*

N number of books are given. 
The ith book has Pi number of pages. 
You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. 
A book will be allocated to exactly one student. Each student has to be allocated at least one book. 
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

NOTE: Return -1 if a valid assignment is not possible

Input:
 List of Books M number of students 

Your function should return an integer corresponding to the minimum number.

Example:

P : [12, 34, 67, 90]
M : 2

Output : 113

There are 2 number of students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 
*/

// number of books should be greater than the number of students

bool check (int P, int M, const vector <int> & books) {
    /*
    page limit: P
    for each book, if it is less than page limit, allocate to a student 
    pass the check if the number of students needed <= M
    */
    int i = 0;
    int x = P;
    int cnt = 1;
    while (i < books.size()) {
        if (cnt > M) return false;
        if (books[i] <= x) {
            x -= books[i];
            i++;
        } else {
            cnt++;
            x = P;
        }
    }
    return cnt <= M;
}

int allocate(int M, const vector <int> & books) {
    if (books.size() < M) return -1;
    long long total = 0;
    for (const int num: books) {
        total += num;
    }
    long long l = 0;
    long long r = total;
    long long ans = 0;
    while (l <= r) {
        long long mid = (l + r) /2;
        if (check (mid, M, books)) {
            ans = mid;
            mid = r - 1;
        } else {
            mid = l + 1;
        }
    }
    return ans;
}

int main () {

    return 0;
}