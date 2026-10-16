#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    if (list1 != nullptr) current->next = list1;
    else current->next = list2;

    return dummy.next;
}

ListNode* createList(int arr[], int n) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    for (int i = 0; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    int a[] = {1, 2, 4};
    int b[] = {1, 3, 4};

    ListNode* list1 = createList(a, 3);
    ListNode* list2 = createList(b, 3);

    printList(mergeTwoLists(list1, list2));

    int c[] = {1, 2, 3};
    ListNode* list3 = createList(c, 3);
    printList(mergeTwoLists(list3, nullptr));

    printList(mergeTwoLists(nullptr, nullptr));

    return 0;
}
