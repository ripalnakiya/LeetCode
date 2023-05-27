/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// APPROACH 1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p=head,*q=head;
        while(p && p->next){
            q = q->next;
            p = p->next->next;
        }
        return q;
    }
};

// APPROACH 2 : USES LESS SPACE
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* middleNode = head;
        int i = 0;
        while(head){
            head = head->next;
            if(i){
                middleNode = middleNode->next;
                i = 0;
            }
            else i = 1;
        }
        return middleNode;
    }
};