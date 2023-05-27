/*
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
*/

#include<iostream>
using namespace std;

// APPROACH 1
class Solution {
public:
    int numberOfSteps(int num) {
        int i = 0;
        while(num){    //while num is true (not equal to zero)
            if(num % 2)    //when num is odd 
                num -=1;
            else
                num /= 2;   //when num is even
            ++i;
        }
        return i;
    }

};

// APPROACH 2: RECURSIVE APPROACH
class Solution {
public:
    int numberOfSteps(int num) {
         if(num == 0){
            return 0;
        }
        if(num % 2 == 0){
            return 1 + numberOfSteps(num/2);
        }
        return 1 + numberOfSteps(num-1);
    }
};