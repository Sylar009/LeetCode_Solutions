/*
Description
You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.

In one operation, you can:

Select two integers a and b from the array.
Replace them with floor(a / 4) and floor(b / 4).
Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.

 

Example 1:

Input: queries = [[1,2],[2,4]]

Output: 3

Explanation:

For queries[0]:

The initial array is nums = [1, 2].
In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
The minimum number of operations required is 1.
For queries[1]:

The initial array is nums = [2, 3, 4].
In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 1].
In the second operation, select nums[1] and nums[2]. The array becomes [0, 0, 0].
The minimum number of operations required is 2.
The output is 1 + 2 = 3.

Example 2:

Input: queries = [[2,6]]

Output: 4

Explanation:

For queries[0]:

The initial array is nums = [2, 3, 4, 5, 6].
In the first operation, select nums[0] and nums[3]. The array becomes [0, 3, 4, 1, 6].
In the second operation, select nums[2] and nums[4]. The array becomes [0, 3, 1, 1, 1].
In the third operation, select nums[1] and nums[2]. The array becomes [0, 0, 0, 1, 1].
In the fourth operation, select nums[3] and nums[4]. The array becomes [0, 0, 0, 0, 0].
The minimum number of operations required is 4.
The output is 4.

 

Constraints:

1 <= queries.length <= 105
queries[i].length == 2
queries[i] == [l, r]
1 <= l < r <= 109
Solutions
Solution 1: Prefix Sum
According to the problem description, suppose the minimum number of operations required to make an element 
x become 
0 is 
p, where 
p is the smallest integer such that 
4^p > x.

Once we know the minimum number of operations for each element, for a range 
[l, r], let 
s be the sum of the minimum operations for all elements in 
[l, r], and let 
mx be the maximum number of operations, which is the number of operations for element 
. Then, the minimum number of operations to make all elements in 
[l, r] become 
0 is 
max((s/2), mx).

We define a function 
f(x) to represent the sum of the minimum operations for all elements in the range 
[l, r]. For each query 
[l, r], we can compute 
s = f(r) - f(l-1) and 
mx = f(r) - f(r-1) to obtain the answer.

The time complexity is 
O(qlogM), where 
q is the number of queries and 
M is the maximum value in the query range. The space complexity is 
O(1).
*/
#include "common_includes.h"

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto f = [&](long long x) {
            long long res = 0;
            long long p = 1;
            int i = 1;
            while (p <= x) {
                long long cnt = min(p * 4 - 1, x) - p + 1;
                res += cnt * i;
                i++;
                p *= 4;
            }
            return res;
        };

        long long ans = 0;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long s = f(r) - f(l - 1);
            long long mx = f(r) - f(r - 1);
            ans += max((s + 1) / 2, mx);
        }
        return ans;
    }
};