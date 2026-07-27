#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>


using namespace std;

#define ll long long

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* dummy1 = list1;
        ListNode* dummy2 = list2;
        while(dummy1){
            v.push_back(dummy1->val);
            dummy1 = dummy1->next;
        }
        while(dummy2){
            v.push_back(dummy2->val);
            dummy2 = dummy2->next;
        }
        sort(v.begin(), v.end());
        ListNode dummy(0);
        ListNode* tail = &dummy;

        for(auto x: v){
            ListNode* curr = new ListNode(x);
            tail->next = curr;
            tail = tail->next;
        }
        ListNode* ans = dummy.next;
        return ans;
    }

    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        vector<ListNode* > v;
        ListNode* dummy1 = list1;
        ListNode* dummy2 = list2;

        while(dummy1){
            v.push_back(dummy1);
            dummy1 = dummy1->next;
        }
        while(dummy2){
            v.push_back(dummy2);
            dummy2 = dummy2->next;
        }
        sort(v.begin(), v.end(), [&] (ListNode* a, ListNode* b){
            return a->val < b->val;
        });
        ListNode dummy3(0);
        ListNode* tail = &dummy3;

        for(auto x : v){
            tail->next = x;
            tail = tail->next;
        }
        tail->next = nullptr;

        ListNode* ans = dummy3.next;
        return ans;
    }
    ListNode* mergeTwoLists3(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        if(list1) tail->next = list1;
        if(list2) tail->next = list2;
        return dummy.next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
