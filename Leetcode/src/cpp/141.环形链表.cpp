/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        ListNode *slowNode, *fastNode1, *fastNode2;
        slowNode = fastNode1 = fastNode2 = head;
        while (slowNode && (fastNode1 = fastNode2->next) &&
               (fastNode2 = fastNode1->next)) {
            if (slowNode == fastNode1 || slowNode == fastNode2)
                return true;
            slowNode = slowNode->next;
        }
        return false;
    }
};
