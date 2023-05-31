/*
Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.
Where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return the array answer.

Example 1:
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

Example 2:
Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
*/
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int size = nums.size(),i;
        vector<int> answer(size);
        vector<int> lsum(size);
        vector<int> rsum(size);

        for(i=1; i<size; i++)
            lsum[i] = lsum[i-1] + nums[i-1];
        // lsum = 0,10,14,22

        for(i=size-2; i>=0; i--)
            rsum[i] = rsum[i+1] + nums[i+1];
        // rsum = 15,11,3,0

        for(i=0; i<size; i++){
            answer[i] = lsum[i]-rsum[i];
            if(answer[i] < 0)
                answer[i] *= -1;
        }

        return answer;
    }
};