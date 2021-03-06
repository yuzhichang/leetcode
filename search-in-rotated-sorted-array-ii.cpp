#include "leetcode.h"

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0;
        int h = n - 1;
        while(l <= h) {
            int m = (l + h) / 2;
            if(A[m] == target) {
                return true;
            } 

            if(A[m] > A[l]) {
                if(A[l] <= target && target < A[m]) {
                    h = m - 1;
                }  else {
                    l = m + 1;
                }
            } else if(A[m] < A[l]){
                if(A[h] >= target && target > A[m]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            } else {
                l++;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;

    int a[] = {1};

    int n = sizeof(a) / sizeof(int);

    cout << sln.search(a, n, 0) << endl;
    cout << sln.search(a, n, 1) << endl;

    return 0;
}