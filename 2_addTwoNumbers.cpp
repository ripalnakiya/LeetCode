/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/


#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// APPROACH 1: MOST OPTIZED SOLUTION
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* p = res;
        int r, carry=0;

        while(carry || l1 || l2){
            r = carry;
            r += (l1) ? l1->val : 0;
            r += (l2) ? l2->val : 0;

            carry = r / 10;

            p = p->next = new ListNode(r%10);
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;            
        }

        return res->next;

    }
};

// APPROACH 2 : THIS WAS THE BASIC Solution ON WHICH THE OPTIMIZATION WAS MADE
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* p = NULL;

        int a, b, r, carry=0, flag=0;

        do{
            if(l1 != NULL){
                a = l1->val;
                l1 = l1->next;
            }
            else a = 0;
            if(l2 != NULL){
                b = l2->val;
                l2 = l2->next;
            }
            else b = 0;

            r = a + b + carry;
            carry = r / 10;
            r = r%10;

            ListNode* node = new ListNode(r);
            
            if(flag != 1){
                p = node;
                res = p;
                flag = 1;
            }
            else{
                p->next = node;
                p = p->next;
            }

        }while(carry != 0 || l1 != NULL || l2 != NULL);

        return res;
    }
};