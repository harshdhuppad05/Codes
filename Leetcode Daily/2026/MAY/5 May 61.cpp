class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }
        temp->next = head;
        k = k % n;
        int steps = n - k;
        ListNode* newTail = head;
        while (steps > 1) {
            newTail = newTail->next;
            steps--;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
