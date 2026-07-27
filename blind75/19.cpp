#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define ll long long


struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* x1): val(x), next(x1){}
};

class Solution {
public:
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* dummy = head;
        int a = n;
        int n1 = 0;
        while(dummy) n1++, dummy = dummy-> next;
        ListNode* dummy2 = head;
        ListNode* ans = dummy2;
        n1 = n1 + 1 - a;
        if(n1 == 1){
            head = head-> next;
            return head;
        }
        while(dummy2){
            if(n1 == 2){
                ListNode* dummy1 = dummy2 -> next -> next;
                dummy2 -> next = dummy1;
                break;
            }
            n1--;
            dummy2 = dummy2->next;
        }
        return ans;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++) fast = fast -> next;
        if(!fast) return head->next;
        while(fast -> next) fast = fast->next, slow = slow->next;

        slow->next = slow->next->next;
        return head;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    ListNode dummy = ListNode(0);

    ListNode* tail = &dummy;


    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        ListNode* curr = new ListNode(x);
        tail -> next = curr;
        tail = tail -> next;
    }
    ListNode* head = dummy.next;
    int a; cin >> a;

    Solution sol;
    ListNode* ans = sol.removeNthFromEnd(head, a);
    
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
}
