#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode *deleteDuplicate(ListNode *head)
{
    ListNode* first, *later, *prev;
    first = head;
    later = first->next;
    while (later != nullptr)
    {
        if(first->val == later->val){
            while(later->next != nullptr && later->next->val == first->val){
                later = later->next;
            }
            if(later->next == nullptr){
                first->next = nullptr;
                break;
            }
            if(first == head){
                head == later->next;
                first = later->next;
                later = later->next->next;
                continue;
            }else {
                prev->next = later->next;
                first = later->next;
                later = first->next;
                continue;
            }
        }
        prev = first;
        first = first->next;
        later = later->next;
    }
    return head;
}
//delete duplicate element
//delete duplicate element from sorted array
ListNode *deleteDuplicates(ListNode *head){
    //delete duplicates element from sorted linked list
    ListNode *first, *later;
    first = head;
    
}
