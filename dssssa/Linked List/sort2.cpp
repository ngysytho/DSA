#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

// Danh sách chính chứa danh sách phụ
struct NestedListNode {
    ListNode* sublist;
    NestedListNode* next;
    NestedListNode(ListNode* l): sublist(l), next(NULL) {}
};

// Hàm merge 2 danh sách liên kết
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Gộp toàn bộ danh sách phụ trong danh sách chính
ListNode* mergeNestedLists(NestedListNode* head) {
    if (!head) return NULL;

    ListNode* merged = head->sublist;
    head = head->next;

    while (head) {
        merged = mergeTwoLists(merged, head->sublist);
        head = head->next;
    }

    return merged;
}

// Hàm hỗ trợ tạo danh sách con
void insertLast(ListNode*& head, ListNode*& tail, int x) {
    ListNode* newNode = new ListNode(x);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    NestedListNode* mainHead = NULL, *mainTail = NULL;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        ListNode* subHead = NULL, *subTail = NULL;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            insertLast(subHead, subTail, x);
        }

        NestedListNode* node = new NestedListNode(subHead);
        if (!mainHead) {
            mainHead = mainTail = node;
        } else {
            mainTail->next = node;
            mainTail = mainTail->next;
        }
    }

    ListNode* result = mergeNestedLists(mainHead);
    printList(result);

    return 0;
}
