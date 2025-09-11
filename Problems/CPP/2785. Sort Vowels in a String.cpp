/*
Description
Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 

Example 1:

Input: s = "lEetcOde"
Output: "lEOtcede"
Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
Example 2:

Input: s = "lYmpH"
Output: "lYmpH"
Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".
 

Constraints:

1 <= s.length <= 105
s consists only of letters of the English alphabet in uppercase and lowercase.
Solutions
Solution 1: Sorting
First, we store all the vowels in the string into an array or list 
vs, then we sort 
vs.

Next, we traverse the string 
s, keeping the consonants unchanged. If it is a vowel, we replace it in order with the letters in the 
vs array.

The time complexity is 
O(n*log(n)), and the space complexity is 
O(n). Where 
n is the length of the string 
s.
*/

#include "common_includes.h"


class Solution {
public:
    string sortVowels(string s) {
        string vs;
        for (auto c : s) {
            char d = tolower(c);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                vs.push_back(c);
            }
        }
        ranges::sort(vs);
        for (int i = 0, j = 0; i < s.size(); ++i) {
            char d = tolower(s[i]);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                s[i] = vs[j++];
            }
        }
        return s;
    }
};