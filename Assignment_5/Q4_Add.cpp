class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* tail = NULL;
        int len = 1;

        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        tail = temp;

        k = k % len;
        if (k == 0) 
            return head;

        temp = head;
        for (int i = 1; i < len - k; i++) {
            temp = temp->next;
        }

        // perform rotation
        tail->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};