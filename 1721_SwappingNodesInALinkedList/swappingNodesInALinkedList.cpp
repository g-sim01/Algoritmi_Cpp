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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i = 1; i < k; ++i) {
            fast = fast->next;
        }
        
        ListNode* swap = fast;

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        int temp = swap->val;
        swap->val = slow->val;
        slow->val = temp;
        
        return head;
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

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Try tests given by LeetCode
    Solution sol;
    
    ListNode* test1 = createList({1, 2, 3, 4, 5});
    cout << "Input:  Lista = [1, 2, 3, 4, 5], k = 2" << endl;
    cout << "Output: "; printList(sol.swapNodes(test1, 2));
    cout << "Expected: [1, 4, 3, 2, 5]\n" << endl;
    deleteList(test1);

    ListNode* test2 = createList({7, 9, 6, 6, 7, 8, 3, 0, 9, 5});
    cout << "Input:  Lista = [7,9,6,6,7,8,3,0,9,5], k = 5" << endl;
    cout << "Output: "; printList(sol.swapNodes(test2, 5));
    cout << "Expected: [7,9,6,6,8,7,3,0,9,5]\n" << endl;
    deleteList(test2);

    ListNode* test3 = createList({1, 2, 3});
    cout << "Input:  Lista = [1, 2, 3], k = 2" << endl;
    cout << "Output: "; printList(sol.swapNodes(test3, 2));
    cout << "Expected: [1, 2, 3]\n" << endl;
    deleteList(test3);

    ListNode* test4 = createList({1, 2});
    cout << "Input:  Lista = [1, 2], k = 1" << endl;
    cout << "Output: "; printList(sol.swapNodes(test4, 1));
    cout << "Expected: [2, 1]\n" << endl;
    deleteList(test4);

    return 0;
}