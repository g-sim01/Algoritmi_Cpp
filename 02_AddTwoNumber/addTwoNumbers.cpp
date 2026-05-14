#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        
        int report = 0;
        while(l1 != nullptr || l2 != nullptr || report != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + report;
            report = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};


ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    //Try test given by LeetCode
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    cout << "Input L1:  ";
    printList(l1);
    cout << "Input L2:  ";
    printList(l2);
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    cout << "Result: ";
    printList(result);
    
    return 0;
}