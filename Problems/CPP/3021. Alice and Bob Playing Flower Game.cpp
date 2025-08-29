/*
Description
Alice and Bob are playing a turn-based game on a circular field surrounded by flowers. The circle represents the field, and there are x flowers in the clockwise direction between Alice and Bob, and y flowers in the anti-clockwise direction between them.

The game proceeds as follows:

Alice takes the first turn.
In each turn, a player must choose either the clockwise or anti-clockwise direction and pick one flower from that side.
At the end of the turn, if there are no flowers left at all, the current player captures their opponent and wins the game.
Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:

Alice must win the game according to the described rules.
The number of flowers x in the clockwise direction must be in the range [1,n].
The number of flowers y in the anti-clockwise direction must be in the range [1,m].
Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

 

Example 1:

Input: n = 3, m = 2
Output: 3
Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).
Example 2:

Input: n = 1, m = 1
Output: 0
Explanation: No pairs satisfy the conditions described in the statement.
 

Constraints:

1 <= n, m <= 105
Solutions
Solution 1: Mathematics
According to the problem description, in each move, the player will choose to move in a clockwise or counterclockwise direction and then pick a flower. Since Alice moves first, when 
 is odd, Alice will definitely win the game.

Therefore, the number of flowers 
 and 
 meet the following conditions:

 is odd;
;
.
If 
 is odd, 
 must be even. At this time, the number of values of 
 is 
 
, the number of values of 
 is 
 
, so the number of pairs that meet the conditions is 
 
 
.

If 
 is even, 
 must be odd. At this time, the number of values of 
 is 
 
, the number of values of 
 is 
 
, so the number of pairs that meet the conditions is 
 
 
.

Therefore, the number of pairs that meet the conditions is 
 
 
 
 
, which is 
 
 
 
 
.

The time complexity is 
, and the space complexity is 
.


Python3
Java
C++
Go
TypeScript
Rust
JavaScript

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long a1 = (n + 1) / 2;
        long long b1 = (m + 1) / 2;
        long long a2 = n / 2;
        long long b2 = m / 2;
        return a1 * b2 + a2 * b1;
    }
};

Solution 2: Mathematics (Optimized)
The result obtained from Solution 1 is 
 
 
 
 
.

If both 
 and 
 are odd, then the result is 
 
 
 
 
, which is 
 
.

If both 
 and 
 are even, then the result is 
 
 
 
 
, which is 
 
.

If 
 is odd and 
 is even, then the result is 
 
 
 
 
, which is 
 
.

If 
 is even and 
 is odd, then the result is 
 
 
 
 
, which is 
 
.

The above four cases can be combined into 
 
.

The time complexity is O(1)
, and the space complexity is O(1)
.
*/

class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((long long) n * m) / 2;
    }
};