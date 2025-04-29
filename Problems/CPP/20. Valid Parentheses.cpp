/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include"common_includes.h"


class Solution {
    public:
    
        bool match(char l, char r) {
            return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
        }
    
        bool isValid(string s) {
            string str_stk;
            for (char c : s) {
                if (c == '(' || c == '{' || c == '[')
                    str_stk.push_back(c);
                else if (str_stk.empty() || !match(str_stk.back(), c))
                    return false;
                else
                    str_stk.pop_back();
            }
            return str_stk.empty();
        }
    };