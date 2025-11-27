ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    int lenA = 0;
    while (tempA != NULL) {
        lenA++;
        tempA = tempA->next;
    }

    int lenB = 0;
    tempB = headB;
    while (tempB != NULL) {
        lenB++;
        tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;

    if (lenA > lenB) {
        int diff = lenA - lenB;
        for (int i = 0; i < diff; i++) {
            tempA = tempA->next;
        }
    } else {
        int diff = lenB - lenA;
        for (int i = 0; i < diff; i++) {
            tempB = tempB->next;
        }
    }

    while (tempA != tempB) {
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return tempA;  // or return tempB; both are same
}