/*
Description
On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer n, an array languages, and an array friendships where:

There are n languages numbered 1 through n,
languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.

Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.

 

Example 1:

Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.
Example 2:

Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
 

Constraints:

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= u​​​​​​i < v​​​​​​i <= languages.length
1 <= friendships.length <= 500
All tuples (u​​​​​i, v​​​​​​i) are unique
languages[i] contains only unique values
Solutions
Solution 1: Simulation + Statistics
For each friendship, if the sets of languages known by the two people do not intersect, we need to teach one language so that they can communicate. We add these people to a hash set 
s.

Then, for each language, we count how many people in set 
s know that language and find the maximum count, denoted as 
mx. The answer is 
|s|-mx, where 
|s| is the size of set 
s.

The time complexity is 
O(m^2*k). Here, 
m is the number of languages, and 
k is the number of friendships.
*/
#include "common_includes.h"
#include <algorithm>

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> s;
        auto check = [&](int u, int v) {
            for (int x : languages[u - 1]) {
                for (int y : languages[v - 1]) {
                    if (x == y) {
                        return true;
                    }
                }
            }
            return false;
        };
        for (auto& e : friendships) {
            int u = e[0], v = e[1];
            if (!check(u, v)) {
                s.insert(u);
                s.insert(v);
            }
        }
        if (s.empty()) {
            return 0;
        }
        vector<int> cnt(n + 1);
        for (int u : s) {
            for (int& l : languages[u - 1]) {
                ++cnt[l];
            }
        }
        return s.size() - ranges::max(cnt);
    }
};