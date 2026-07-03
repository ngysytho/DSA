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
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
}

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy(0);
        ListNode* tail = &dummy;
        int a = 0;
        while(l1 && l2){
            if(l1->val + l2-> val < 10){
                tail->next = l1->val + l2->val + a;
                a=0;
            }
            else{
                a++;
                tail->next = (l1->val + l2->val) - 10;
            }
            tail = tail->next;
        }
        if(l1 != NULL){
            tail->next = l1->val+a;
            tail = tail->next;
            tail->next = l1;
        }
        else{
            tail->next = l2->val+a;
            tail = tail->next;
            tail->next = l2;
        }
    }
};

void printList(ListNode* head){
    while (head != NULL){
        cout << head->val <<" ";
        head = head->next;
    }
}

int main(){
    ListNode* head1 = NULL, tail1 = NULL;
    ListNode* head2 = NULL, tail2 = NULL;

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ListNode* list1 = insertLast(head1, tail1, x);
    }

    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        ListNode* list2 = insertLast(head2, tail2, x);
    }

    Solution sol;
    ListNode* mergetwosum = sol.addTwoNumbers(list1, list2);
    printList(mergetwosum);
}
