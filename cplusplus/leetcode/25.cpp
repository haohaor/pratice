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
  ListNode* reverseKGroup(ListNode* head, int k) {
    int cnt = 1;
    ListNode *pre = head, *last = head, *now = head -> next;
    while (now) {
      cnt ++;
      last -> next = now -> next;
      now -> next = pre;
      now = last -> next;
      pre = now;
      if (cnt == k) break;
    }
    return pre;
  }
};