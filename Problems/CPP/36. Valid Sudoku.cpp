/*
36. Valid Sudoku


Description
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:



Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
Solutions
Solution 1: Traversal once
The valid sudoku satisfies the following three conditions:

The digits are not repeated in each row;
The digits are not repeated in each column;
The digits are not repeated in each 3*3
 box.
Traverse the sudoku, for each digit, check whether the row, column and 
 box it is in have appeared the digit. If it is, return false. If the traversal is over, return true.

The time complexity is O(C)
 and the space complexity is O(C)
, where C
 is the number of empty spaces in the sudoku. In this question, C = 81
.
*/

#include "common_includes.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen digits per row, per column, per 3x3 box
    vector<vector<bool>> row(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> sub(9, vector<bool>(9, false));

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c = board[i][j];
            if (c == '.') continue;          // ignore empty cells

            int num = c - '0' - 1;           // map '1'..'9' -> 0..8
            int k = (i / 3) * 3 + (j / 3);   // which 3x3 box

            // If digit already seen in row/col/box, invalid
            if (row[i][num] || col[j][num] || sub[k][num])
                return false;

            // Mark digit as seen
            row[i][num] = col[j][num] = sub[k][num] = true;
        }
    }
    return true; // no conflicts found
    }
};