/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort (strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) return res;
            res += first[i];
        }
        return res;
    }
};
