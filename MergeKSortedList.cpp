#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}  ListNode(int x) : val(x), next(nullptr){}  ListNode(int x, ListNode next) : val(x), next(next){}
                                                                                                                                      
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    while (true)
    {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL && lists[i]->val < min)
            {
                min = lists[i]->val;
                index = i;
            }
        }
        if (index == -1)
        {
            break;
        }
        cur->next = lists[index];
        cur = cur->next;
        lists[index] = lists[index]->next;
    }
    return head->next;
}