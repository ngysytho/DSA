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
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto x : lists){
            while(x){
                v.push_back(x->val);
                x = x->next;
            }
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        vector<ListNode* > v;
        priority_queue<ListNode*, vector<ListNode*>, decltype([](ListNode* a, ListNode* b){
            return a->val < b->val;
        })> qu;
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype(compare)
        > pq(compare);
        
        for(auto x : lists){
            while(x){
                v.push_back(x);
                x = x->next;
            }
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
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
