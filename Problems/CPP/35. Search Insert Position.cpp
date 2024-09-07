/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/
class Solution {
public:
    int binary_search(vector<int>& nums, int key) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low +(high-low)/2;
            if (nums[mid] == key){
                return mid;
            }
            if ( key> nums[mid] ) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return nums.size();
        return binary_search(nums, target);
    }
};