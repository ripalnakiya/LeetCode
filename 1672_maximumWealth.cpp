/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
*/

#include<iostream>
#include<vector>

using namespace std;

// APPROACH 1 : BEST AND OPTIMISED
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int wealth = 0;
        for(vector<int> customer : accounts)
        {
            int sum = 0;
            for(int bank : customer)
                sum += bank;
            if(sum>wealth)
                wealth = sum;
        }

        return wealth;
    }
};

// APPROACH 2 : USING NAIVE ARRAYS
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int wealth = 0;
        int row = accounts.size();
        int col = accounts[0].size();
        for(int i=0; i<row; i++)
        {
            int sum = 0;
            for(int j=0; j<col; j++)
            {
                sum += accounts[i][j];
            }
            if(sum > wealth)
                wealth = sum;
        }
        return wealth;
    }
};