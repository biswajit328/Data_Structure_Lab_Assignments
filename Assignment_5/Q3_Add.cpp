class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                flag = true;
                break;
            }
        }

        // No cycle found
        if (flag == false)
            return NULL;

        // Step 2: Find the starting node of the cycle
        ListNode* temp = head;
        while (temp != slow) {
            slow = slow->next;
            temp = temp->next;
        }

        // Step 3: Remove the cycle
        ListNode* ptr = temp;
        while (ptr->next != temp) {
            ptr = ptr->next;
        }
        ptr->next = NULL;  // Break the cycle

        return temp;  // Return the start of the cycle
    }
};