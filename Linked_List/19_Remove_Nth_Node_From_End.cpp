class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Dummy node handles the case when we remove the head
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *fast = dummy;
    ListNode *slow = dummy;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }

    // Move both until fast reaches the last node
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    // Remove the nth node from the end
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;
  }
};
