Node* Reverse(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    Node* next = NULL;
    Node* current = head;
    Node* prev = NULL;

    int count = 0;

    // Step 1: Reverse first k nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Step 2: Recursively call for the remaining list
    if (next != NULL) {
        head->next = Reverse(next, k);
    }

    // Step 3: Return new head of this segment (prev)
    return prev;
}