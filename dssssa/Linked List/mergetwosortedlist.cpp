#include <bits/stdc++.h>
using namespace std;

int n, m;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertLast(ListNode* &head, ListNode* &tail, int x){
    ListNode* newNode = new ListNode(x);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = NULL, *tail1 = NULL;
    ListNode* head2 = NULL, *tail2 = NULL;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insertLast(head1, tail1, x);
    }

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        insertLast(head2, tail2, x);
    }

    Solution sol;
    ListNode* result = sol.addTwoNumbers(head1, head2);
    printList(result);
    return 0;
}
