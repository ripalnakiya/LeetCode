/*
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.

Given an integer n, return true if n is strictly palindromic and false otherwise.

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.
Example 2:

Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.
*/
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        //Consider the representation of the given number in the base n - 2
        //The number n in base (n - 2) is always 12, which is not palindromic.
        return false;
    }
};


// THE PROPER APPOACH
class Solution {
public:
    int isPalindromeAtBase(int n, int base){
        string str = "",rev;
        int digit;
        while(n>0){
            digit = n % base;
            str += to_string(digit);
            n = n/base;
        }

        // we get reversed number at given base, so storing it in rev
        // and then reversing the str to get original number at given base
        rev = str;
        reverse(str.begin(),str.end());
 
        // If the number is palindrome at given base , return 1;
        if(str.compare(rev) == 0)
            return 1;
        return 0;
    }

    bool isStrictlyPalindromic(int n) {
        int flag = 0;
        for(int i=2; i<= n-2; i++){
            flag = isPalindromeAtBase(n,i);
            if(flag == 0)//break even if the given number is not palindromic at base i, once
                break;
        }
        return (flag ? true : false);
    }
};