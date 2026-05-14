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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = head;
        int i = 1;
        
        while(fast->next != nullptr) {
            i++;
            fast = fast->next;
            if(i > n) slow = slow->next;
        }
        
        ListNode* nodeToDelete = slow->next; 
        
        slow->next = slow->next->next;
        
        delete nodeToDelete; 
        
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    // Try tests given by LeetCode
    Solution sol;
    
    ListNode* test1 = createList({1, 2, 3, 4, 5});
    cout << "Input: head = [1,2,3,4,5], n = 2" << endl;
    cout << "Result: "; printList(sol.removeNthFromEnd(test1, 2));
    cout << "Expected:    [1,2,3,5]\n" << endl;

    ListNode* test2 = createList({1});
    cout << "Input: head = [1], n = 1" << endl;
    cout << "Result: "; printList(sol.removeNthFromEnd(test2, 1));
    cout << "Expected:    []\n" << endl;

    ListNode* test3 = createList({1, 2});
    cout << "Input: head = [1,2], n = 1" << endl;
    cout << "Result: "; printList(sol.removeNthFromEnd(test3, 1));
    cout << "Expected:    [1]\n" << endl;

    ListNode* test4 = createList({1, 2});
    cout << "Input: head = [1,2], n = 2" << endl;
    cout << "Result: "; printList(sol.removeNthFromEnd(test4, 2));
    cout << "Expected:    [2]\n" << endl;

    return 0;
}