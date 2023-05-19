/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Method 1
        // for(int i = 1 ; i < nums.size(); i++ )
        //     nums[i] += nums[i-1];

        // Method 2
        int prev = 0;
        for(auto& num : nums){
            num += prev;
            prev = num;
        }
        return nums;

    }
};

int main(){

    vector<int> nums = {1,2,3,4};

    Solution sol;

    vector<int> array = sol.runningSum(nums);

    for (auto& num : array)
        cout << num << ", ";

    return 0;
}