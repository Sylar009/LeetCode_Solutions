/*
Description
You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.

 

Example 1:

Input: num1 = 3, num2 = -2
Output: 3
Explanation: We can make 3 equal to 0 with the following operations:
- We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
- We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
- We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
It can be proven, that 3 is the minimum number of operations that we need to perform.
Example 2:

Input: num1 = 5, num2 = 7
Output: -1
Explanation: It can be proven, that it is impossible to make 5 equal to 0 with the given operation.
 

Constraints:

1 <= num1 <= 109
-109 <= num2 <= 109
Solutions
Solution 1: Enumeration
If we operate k
 times, then the problem essentially becomes: determining whether num1 - k* num2
 can be split into the sum of 
 
k2^i's.

Let's assume x = num1 - k* num2
. Next, we discuss in categories:

If x < 0
, then x
 cannot be split into the sum of k2^i's, because 2^i
, which obviously has no solution;
If the number of 
1's in the binary representation of 
x is greater than k2^i's.
, there is also no solution in this case;
Otherwise, for the current K
, there must exist a splitting scheme.
Therefore, we start enumerating k
 from 1
. Once we find a k
 that meets the condition, we can directly return the answer.

The time complexity is O(log x)
, and the space complexity is O(1)
.
*/

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        using ll = long long;
        for (ll k = 1;; ++k) {
            ll x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (__builtin_popcountll(x) <= k && k <= x) {
                return k;
            }
        }
        return -1;
    }
};