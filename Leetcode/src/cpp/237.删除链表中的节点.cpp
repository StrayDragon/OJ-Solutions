/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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

    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* tmp = node->next->next;
        delete node->next;
        node->next = tmp;
    }
    void deleteNode2(ListNode* node) {
        //memery leak
        *node = *(node->next);
    }
};

