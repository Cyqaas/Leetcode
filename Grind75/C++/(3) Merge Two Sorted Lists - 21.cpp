/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // create a merged list variable and current node tracker tied to it
        ListNode* mergedList = new ListNode(); 
        ListNode* currNode = mergedList; 

        // iterate through both lists and compare the values
        while (list1 != NULL && list2 != NULL)
        {
            // add the list 1 value as the next node if it is less than or
            // equal to the list 2 value
            if (list1->val <= list2->val) 
            {
                currNode->next = new ListNode(list1->val); 
                list1 = list1->next;
            }
            // add the list 2 value as the next node if it is less than or
            // equal to the list 1 value 
            else if (list1->val > list2->val) 
            {
                currNode->next = new ListNode(list2->val);
                list2 = list2->next;
            }

            // get the most up to date node 
            currNode = currNode->next;
        } 

        // add any remaining nodes to the list
        if (list1 != NULL) 
        {
            currNode->next = list1; 
        }
        else if (list2 != NULL) 
        {
            currNode->next = list2; 
        }

        // return the merged list
        return mergedList->next;
    }
};
