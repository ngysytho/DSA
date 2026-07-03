#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap: giá trị nhỏ nhất ưu tiên
    }
};

class Solution {
public:
    // Cách 1: Gộp từng cặp danh sách (merge tuần tự)
    ListNode* mergeKLists_v1(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;

        ListNode* merged = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            ListNode dummy1(0);
            ListNode* tail1 = &dummy1;
            ListNode* l1 = merged;
            ListNode* l2 = lists[i];

            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    tail1->next = l1;
                    l1 = l1->next;
                } else {
                    tail1->next = l2;
                    l2 = l2->next;
                }
                tail1 = tail1->next;
            }

            if (l1) tail1->next = l1;
            if (l2) tail1->next = l2;

            merged = dummy1.next;
        }

        return merged;
    }

    // Cách 2: Dùng heap (priority_queue) – nhanh hơn
    ListNode* mergeKLists_v2(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

    for (auto node : lists) {
        if (node) pq.push(node);
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* smallest = pq.top();
        pq.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next) {
            pq.push(smallest->next);
        }
    }

    return dummy.next;
}

};

// ---------- Hỗ trợ nhập / in danh sách ----------
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

    vector<ListNode*> lists;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        ListNode* head = NULL, *tail = NULL;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            insertLast(head, tail, x);
        }
        lists.push_back(head);
    }

    int method;
    cin >> method; // Nhập 1 hoặc 2 để chọn cách gộp

    Solution sol;
    ListNode* result = nullptr;

    if (method == 1)
        result = sol.mergeKLists_v1(lists);
    else if (method == 2)
        result = sol.mergeKLists_v2(lists);
    else
        cout << "Lựa chọn không hợp lệ!" << endl;

    if (result) printList(result);

    return 0;
}
