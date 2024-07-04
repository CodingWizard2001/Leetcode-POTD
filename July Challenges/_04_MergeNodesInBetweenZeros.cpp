// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0. For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's. Return the head of the modified linked list.


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head -> next;

        while(current){
            ListNode* running = current;
            int sum = 0;
            while(running -> val){
                sum += running -> val;
                running = running -> next;
            }
            current -> val = sum;
            current -> next = running -> next;
            current = running -> next;
        }
        return head -> next;
    }
};

ListNode* createNode(int val) {
    return new ListNode(val);
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while(current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    ListNode* head = createNode(0);
    head->next = createNode(3);
    head->next->next = createNode(1);
    head->next->next->next = createNode(0);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next->next = createNode(0);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* mergedHead = sol.mergeNodes(head);

    cout << "Merged List: ";
    printList(mergedHead);
}