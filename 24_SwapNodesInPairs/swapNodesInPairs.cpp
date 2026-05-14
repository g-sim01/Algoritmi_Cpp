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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first; 
        }
        
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
    
    ListNode* test1 = createList({1, 2, 3, 4});
    cout << "Input:  [1, 2, 3, 4]" << endl;
    cout << "Output: "; printList(sol.swapPairs(test1));
    cout << "Expected: [2, 1, 4, 3]\n" << endl;

    ListNode* test2 = nullptr;
    cout << "Input:  []" << endl;
    cout << "Output: "; printList(sol.swapPairs(test2));
    cout << "Expected: []\n" << endl;

    ListNode* test3 = createList({1});
    cout << "Input:  [1]" << endl;
    cout << "Output: "; printList(sol.swapPairs(test3));
    cout << "Expected: [1]\n" << endl;

    ListNode* test4 = createList({1, 2, 3});
    cout << "Input:  [1, 2, 3]" << endl;
    cout << "Output: "; printList(sol.swapPairs(test4));
    cout << "Expected: [2, 1, 3]\n" << endl;

    return 0;
}