/*
Description
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000
Solutions
Solution 1: Construction
We can start from 
 and alternately add positive and negative numbers to the result array. We repeat this process 
 
 times. If 
 is odd, we add 
 to the result array at the end.

The time complexity is 
O(n), where 
n is the given integer. Ignoring the space used for the answer, the space complexity is 
O(1).
*/

#include "common_includes.h"

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for (int i = 1, j = 0; i <= n / 2; ++i) {
            ans[j++] = i;
            ans[j++] = -i;
        }
        return ans;
    }
};

/*

Solution 2: Construction + Mathematics
We can also add all integers from 
1 to 
n-1 to the result array, and finally add the opposite of the sum of the first 
n-1 integers, which is 
 
-(n(n-1)/2), to the result array.

The time complexity is 
O(n), where 
n is the given integer. Ignoring the space used for the answer, the space complexity is 
O(1).

*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        ans[n - 1] = -(n - 1) * n / 2;
        return ans;
    }
};