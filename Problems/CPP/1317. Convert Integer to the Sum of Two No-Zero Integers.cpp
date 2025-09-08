/*
Description
No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 

Constraints:

2 <= n <= 104
Solutions
Solution 1: Direct Enumeration
Starting from 
1, we enumerate 
a, then 
b=n-a. For each 
a and 
b, we convert them to strings and concatenate them, then check if they contain the character '0'. If they do not contain '0', we have found the answer and return 
[a,b].

The time complexity is 
O(n*logn), where 
 is the integer given in the problem. The space complexity is 
O(logn).
*/
#include "common_includes.h"

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1;; ++a) {
            int b = n - a;
            if ((to_string(a) + to_string(b)).find('0') == -1) {
                return {a, b};
            }
        }
    }
};

/*
Solution 2: Direct Enumeration (Alternative Approach)
In Solution 1, we converted 
a and 
b into strings and concatenated them, then checked if they contained the character '0'. Here, we can use a function 
f(x) to check whether 
x contains the character '0', and then directly enumerate 
a, checking whether both 
a and 
b = n-a do not contain the character '0'. If they do not, we have found the answer and return 
[a,b].

The time complexity is 
O(n*logn), where 
 is the integer given in the problem. The space complexity is 
O(1).

*/

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto f = [](int x) {
            for (; x; x /= 10) {
                if (x % 10 == 0) {
                    return false;
                }
            }
            return true;
        };
        for (int a = 1;; ++a) {
            int b = n - a;
            if (f(a) && f(b)) {
                return {a, b};
            }
        }
    }
};