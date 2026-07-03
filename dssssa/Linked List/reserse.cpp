// #include <bits/stdc++.h>
// #define ll long long

// using namespace std;
// int k;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// void insertLast(ListNode *&head, ListNode *&tail, int x)
// {
//     ListNode *newNode = new ListNode(x);
//     if (!head)
//     {
//         head = tail = newNode;
//     }
//     else
//     {
//         tail->next = newNode;
//         tail = tail->next;
//     }
// }

// void printList(ListNode *head)
// {
//     while (head)
//     {
//         cout << head->val << " ";
//         head = head->next;
//     }
// }

// class Solution
// {
// public:
//     ListNode *reserseKGroup(ListNode *head, int k)
//     {
//         int m = k;
//         ListNode dummy(0);
//         ListNode *tail = &dummy;
//         ListNode *dummy1 = &dummy;
//         int x = head->val;
//         while (!head)
//         {
//             if (m == 1)
//             {
//                 m = k;
//                 int c = head->val;
//                 tail->val = x;
//                 dummy1->val = c;
//                 dummy1 = tail;
//                 head = head->next;
//                 tail->next = head;
//                 x = head->val;
//             }
//             else
//             {
//                 m--;
//                 tail->next = head;
//                 head = head->next;
//             }
//         }
//         return dummy.next;
//     }
// };

// int main()
// {
//     int n;
//     ListNode *head = NULL, *tail = NULL;
//     cin >> n >> k;
//     for (int i = 0; i < n; i++)
//     {
//         int val;
//         cin >> val;
//         insertLast(head, tail, val);
//     }
//     Solution sol;
//     ListNode *result = NULL;
//     result = sol.reserseKGroup(head, k);
//     printList(result);
// }
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int k;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertLast(ListNode *&head, ListNode *&tail, int x)
{
    ListNode *newNode = new ListNode(x);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;

        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        curr = head;
        while (count >= k)
        {
            ListNode *first = curr;
            ListNode *prev_temp = NULL;
            ListNode *next_temp = NULL;

            // Reverse k nodes
            for (int i = 0; i < k; i++)
            {
                next_temp = curr->next;
                curr->next = prev_temp;
                prev_temp = curr;
                curr = next_temp;
            }

            // Connect the reversed group to the list
            prev->next = prev_temp;
            first->next = curr;
            prev = first;

            count -= k;
        }

        return dummy.next;
    }
};

int main()
{
    int n;
    ListNode *head = NULL, *tail = NULL;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertLast(head, tail, val);
    }

    Solution sol;
    ListNode *result = sol.reverseKGroup(head, k);
    printList(result);

    return 0;
}