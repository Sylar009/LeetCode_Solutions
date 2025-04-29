/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
#include"common_includes.h"

class Solution {
public:

    // Classical binary search algorithm, but slightly different
    // if cannot find the key, return the position where can insert the key 
    int binarySearch(vector<int>& A, int low, int high, int key){
        while(low<=high){
            int mid = low + (high - low)/2;
            if (key == A[mid]) return mid;
                if (key > A[mid]){
                    low = mid + 1;
                }else {
                    high = mid -1;
                }
            }
        return low;
    }

    
    double findMedianSortedArrayHelper(vector<int>& A, vector<int>& B, int lowA, int highA, int lowB, int highB) {

        int m = A.size();
        int n = B.size();

        // Take the A[middle], search its position in B array
        int mid = lowA + (highA - lowA)/2;
        int pos = binarySearch(B, lowB, highB, A[mid]);
        int num = mid + pos;

        // If the A[middle] in B is B's middle place, then we can have the result
        if (num == (m+n)/2){
            // If two arrays total length is odd, just simply return the A[mid]
            // Why not return the B[pos] instead ? 
            //   suppose A={ 1,3,5 } B={ 2,4 }, then mid=1, pos=1
            //   suppose A={ 3,5 }   B={1,2,4}, then mid=0, pos=2
            //   suppose A={ 1,3,4,5 }   B={2}, then mid=1, pos=1
            // You can see, the `pos` is the place A[mid] can be inserted, so return A[mid]
            if ((m+n)%2==1){
                return A[mid];
            }
        
            // If tow arrys total length is even, then we have to find the next one.
            int next;

            // If both `mid` and `pos` are not the first postion.
            // Then, find max(A[mid-1], B[pos-1]). 
            // Because the `mid` is the second middle number, we need to find the first middle number
            // Be careful about the edge case
            if (mid>0 && pos>0){ 
                next = A[mid-1]>B[pos-1] ? A[mid-1] : B[pos-1];
            }else if(pos>0){
                next = B[pos-1];
            }else if(mid>0){
                next = A[mid-1];
            }
        
            return (A[mid] + next)/2.0;
        }
        // if A[mid] is in the left middle place of the whole two arrays
        //
        //         A(len=16)        B(len=10)
        //     [................] [...........]
        //            ^             ^
        //           mid=7         pos=1
        //
        //  move the `low` pointer to the "middle" position, do next iteration.
        if (num < (m+n)/2){
            lowA = mid + 1;
            lowB = pos; 
            if ( highA - lowA > highB - lowB ) {
                return findMedianSortedArrayHelper(A, B, lowA, highA, lowB, highB);
            }
            return findMedianSortedArrayHelper(B, A, lowB, highB, lowA, highA);
        }
        
        // if A[mid] is in the right middle place of the whole two arrays
        else if (num > (m+n)/2) {
            highA = mid - 1;
            highB = pos-1;
            if ( highA - lowA > highB - lowB ) {
                return findMedianSortedArrayHelper(A, B, lowA, highA, lowB, highB);
            }
            return findMedianSortedArrayHelper(B, A, lowB, highB, lowA, highA);
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //checking the edge cases
        if ( m == 0 && n == 0 ) return 0.0;
        
        //if the length of array is odd, return the middle one
        //if the length of array is even, return the average of the middle two numbers  
        if ( m == 0 ) return n % 2 == 1 ? nums2[n/2] : (nums2[n/2-1] + nums2[n/2])/2.0;
        if ( n == 0 ) return m % 2 == 1 ? nums1[m/2] : (nums1[m/2-1] + nums1[m/2])/2.0;
    
        //let the longer array be A, and the shoter array be B
        if ( m > n ){
            return findMedianSortedArrayHelper(nums1, nums2, 0, m-1, 0, n-1);
        }
        
        return findMedianSortedArrayHelper(nums2, nums1, 0, n-1, 0, m-1);
    }
};