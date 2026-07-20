#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }

};

class Solution {
public:
    bool hasCycle_burstForce(ListNode *head) {
        unordered_set<ListNode*> se;
        unordered_map<ListNode*, bool> mp;
        
        ListNode* dummy = head;
        while(dummy != NULL){
            if(se.count(dummy)){
                return true;
            }
            se.insert(dummy);
            dummy = dummy->next;
        }
        return false;
    }

     bool hasCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;

        while(second && second->next != NULL){
            first = first->next;
            second = second ->next -> next;
            if(first == second) return true;
        }
        return false;
    }
};

int main(){
    int n;
    cin >> n;
    // ListNode *head = NULL;
    // ListNode *tail = NULL;
    // for(int i = 1; i <= n; i++){
    //     int x;
    //     cin >> x;
    //     ListNode *curr = new ListNode(x);
        
    //     if(head == NULL){
    //         head = curr;
    //         tail = curr;
    //     }else{
    //         tail->next = curr;
    //         tail = curr;
    //     }
    // }
    ListNode dummy = ListNode(0);
    ListNode *tail = &dummy;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        tail -> next = new ListNode(x);
        tail = tail->next;
    }

    ListNode *head = dummy.next;
    Solution sol;
    cout << sol.hasCycle(head);
}