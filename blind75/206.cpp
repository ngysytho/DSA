#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <climits>
#include <utility>
#include <map>
#include <cmath>
#include <bitset>
#include <bit>
#include <cstdint>

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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;

        ListNode ans = ListNode(0);
        ListNode* tailAns = &ans;
        ListNode* dummy = head;

        while(dummy){
            s.push(dummy);
            dummy = dummy->next;
        }

        while(!s.empty()){
            tailAns->next = s.top();
            s.pop();
            tailAns = tailAns->next;
        }
        tailAns->next = nullptr;
        return ans.next;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
