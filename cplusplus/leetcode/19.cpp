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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* pre = nullptr, *now = head;
    int cnt = 0;
    while (now) {
      cnt ++;
      if (cnt == n + 1 && !pre) pre = head;
      if (now -> next) {
        now = now -> next;
        if (pre) pre = pre -> next;
      } else {
        break;
      }
    }
    if (pre) {
      pre -> next = pre -> next -> next;
      return head;
    } else {
      return head -> next;
    }
  }
};