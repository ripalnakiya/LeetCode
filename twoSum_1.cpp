/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        int num, complement;

        // APPROACH 1
        // INSERTING ELEMENTS IN myMap USING DIFFERENT LOOP
        // for(int i=0; i<nums.size(); ++i)
        //     myMap.insert(make_pair(nums[i],i ));

        // for(int i=0; i<nums.size(); ++i){
        //     complement = target - nums[i];
        //     auto iter = myMap.find(complement);
        //     if (iter != myMap.end() && i!=myMap[complement]){
        //         return {i, myMap[complement]}
        //     }
        // }


        // APPROACH 2 : USES LESS TIME AND SPACE COMPLEXITY THAN AAPROACH 1
        // INSERTING ELEMENTS IN IN THE SAME LOOP AS SEARCHING
        // though this method gives indices in reverse order but the answer is true
        for(int i=0; i<nums.size(); ++i){
            num = nums[i];
            complement =  target - num ;
            if (myMap.count(complement))
                return {i, myMap[complement]};
            myMap[num] = i;
        }

        return {};
    }
};