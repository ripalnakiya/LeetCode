/*
Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

Example 1:
Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.

Example 2:
Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.

Example 3:
Input: nums = [1,1,1]
Output: false
Explanation: The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int size = nums.size();
        int i, count=0;
        for(i=1; i<size; i++){
            if(nums[i]<=nums[i-1]){ // IF THE PREVIOUS NUMBER IS GREATER THAN CURRENT
                if(count){   // IF COUNT IS ALREADY ONE
                    return false;
                }
                if( i>1     // IF I IS 2 OR MORE THAN 2 (USE TESTCASE [2,3,1,2] TO UNDERSTRAND THIS IF CONDITION)
                    && i+1 < size   // IF I+1 IS LESS THAN THE SIZE
                    && nums[i+1] <= nums[i-1]   // IF THE NEXT NUMBER IS LESS THAN PREVIOUS NUMBER
                    && nums[i] <= nums[i-2]){    // IF THE NUMBER PREVIOUS TO THE PREVOIUS NUMBER IS MORE THAN CURRENT NUBMER
                    return false;   // THEN RETURN FALSE, BECAUSE REMOVAL OF ONE NUMBER CANNOT MAKE THE ARRAY STRICTLY INCREASING
                }
                count+=1;
            }
        }
        return count<=1;
    }
};