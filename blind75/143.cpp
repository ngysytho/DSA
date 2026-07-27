#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>


using namespace std;

#define ll long long

struct ListNode1 {
    int val;
    ListNode1 *next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1 *next1) : val(x), next(next1) {}
};

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
    ListNode(int x, ListNode *next1){
        val = x;
        next = next1;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution1 {
// public:
//     void reorderList(ListNode* head) {
//         ListNode* ptr=head;
//         deque<ListNode*> dq;
//         while(ptr){
//             dq.push_back(ptr);
//             ptr=ptr->next;
//         }
//         int n=dq.size();
//         for(int i=0;i<n;i++){
//             if(i%2==0){
//                 ptr=dq.front();
//                 ptr->next=dq.back();
//                 dq.pop_front();
//             }else{
//                 ptr=dq.back();
//                 ptr->next=dq.front();
//                 dq.pop_back();
//             }
//         }
//         ptr->next=nullptr;
//     }
// };
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* dummy = head;
        vector<int> v;
        int n = 0;
        while(dummy != NULL){
            v.push_back(dummy->val);
            dummy = dummy->next;
            n++;
        }
        ListNode* tail = head;
        ListNode* dummy1 = tail;
        tail = tail->next;
        int left = 1, right = v.size() - 1;
        while(left <= right && tail != NULL){
                tail->val = v[right];
                right--;
                tail = tail -> next;
                
                if(tail != NULL){
                    tail->val = v[left];
                    left++;
                    tail = tail ->next;
                }
        }
        head = dummy1;
    }

    void reorderList1(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        deque<ListNode*> qd;
        ListNode *dummy = head;

        while(dummy){
            qd.push_back(dummy);
            dummy = dummy->next;
        }
        int n =qd.size();
        ListNode* ans = qd.front();
        qd.pop_front();

        for(int i = 1; i < n; i++){
            if(i % 2 == 0){
                ans->next = qd.front();
                ans = ans->next;
                qd.pop_front();
            }
            else{
                ans->next = qd.back();
                ans = ans->next;
                qd.pop_back();
            }
        }
        ans -> next = NULL;
    }
    void reorderList2(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // BƯỚC 1: Tìm điểm giữa
        ListNode* slow = head;
        ListNode* fast = head;
        // Chạy fast 2 bước, slow 1 bước
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // BƯỚC 2: Đảo ngược nửa sau của danh sách
        ListNode* prev = NULL;
        ListNode* curr = slow->next; // Bắt đầu nửa sau
        slow->next = NULL;           // Ngắt nửa đầu ra khỏi nửa sau (rất quan trọng)

        while (curr != NULL) {
            ListNode* nextTemp = curr->next; // Giữ lại node tiếp theo
            curr->next = prev;               // Đảo chiều mũi tên
            prev = curr;                     // Nhích prev lên
            curr = nextTemp;                 // Nhích curr lên
        }
        // Lúc này prev đang trỏ tới head của danh sách nửa sau (đã bị đảo ngược)

        // BƯỚC 3: Gộp đan xen 2 danh sách
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            // Giữ lại vị trí tiếp theo của cả 2 list
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            // Nối: node nửa đầu -> node nửa sau
            first->next = second;
            // Nối: node nửa sau -> node kế tiếp của nửa đầu
            second->next = tmp1;

            // Di chuyển 2 con trỏ lên bước tiếp theo
            first = tmp1;
            second = tmp2;
        }
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//
    int n; cin >> n;
    ListNode dummy(0);
    ListNode *tail = &dummy;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ListNode *curr = new ListNode(x);
        tail -> next =curr;
        tail = curr;
    }

    ListNode *head = dummy.next;
}
