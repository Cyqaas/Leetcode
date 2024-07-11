using namespace std;
#include <cstddef>
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    // solution:
    // iterate over every list node and add it into a stack, that way we can create a
    // reversed list.

    stack<ListNode *> stck;
    ListNode *curr = head;
    ListNode *reverseList = new ListNode();

    while (curr != NULL)
    {
        stck.push(new ListNode(curr->val));
        curr = curr->next;
    }

    curr = NULL;
    ListNode *reverseCurr = reverseList;

    while (!stck.empty())
    {
        curr = stck.top();
        reverseCurr->next = new ListNode(curr->va);
        reverseCurr = reverseCurr->next;
        stck.pop();
    }

    return reverseList->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode *reverse = reverseList(head);
}