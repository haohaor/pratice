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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](pair<int, ListNode*> &a, pair<int, ListNode*> &b) {
      return a.first > b.first;
    };
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, 
        decltype(cmp)> que(cmp);
    for (auto i = 0; i < lists.size(); ++ i) {
      if (lists[i]) que.push({lists[i] -> val, lists[i]});
    }
    ListNode *ans = nullptr, *now = nullptr;
    while (!que.empty()) {
      auto node = que.top();
      auto nextNode = node.second -> next;
      que.pop();
      if (!ans) {
        ans = node.second;
        now = ans;
      } else {
        now -> next = node.second;
      }
      if (nextNode) {
        que.push({nextNode -> val, nextNode});
      }
      now = node.second;
    }
    return ans;
  }
};