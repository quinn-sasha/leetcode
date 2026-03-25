class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* node = head;
        std::unordered_set<ListNode*> visited;
        while (node) {
            if (visited.find(node) != visited.end()) {
                return true;
            }
            visited.insert(node);
            node = node->next;
        }
        return false;
    }
};
