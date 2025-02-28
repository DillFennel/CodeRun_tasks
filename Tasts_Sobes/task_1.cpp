#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
ListNode* ReverseList(ListNode* head){
    ListNode* pre_verc, *curr_verc, *next_verc;
    pre_verc = head;
    curr_verc = head->next;
    head->next = nullptr;
    next_verc = curr_verc->next;
    do{
        curr_verc->next = pre_verc;
        pre_verc = curr_verc;
        curr_verc = next_verc;
        next_verc = curr_verc->next;

    }while(next_verc != nullptr);
    curr_verc->next = pre_verc;
    return curr_verc;
}
int main(){
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2, a);
    ListNode* c = new ListNode(3, b);
    ListNode* d = new ListNode(4, c);

    ListNode* e = ReverseList(d);
    cout<<e->val;
}