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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* curr = head;
        ListNode* prox = curr->next;
        ListNode* flag = prox;
        
        while (prox != nullptr && prox->next != nullptr) {
            curr->next = prox->next;
            prox->next = curr->next->next;
            
            curr = curr->next;
            prox = prox->next;
        }
        
        curr->next = flag;
        
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
    cout << "Input:  [1, 2, 3, 4, 5]" << endl;
    cout << "Output: "; printList(sol.oddEvenList(test1));
    cout << "Expected: [1, 3, 5, 2, 4]\n" << endl;
    deleteList(test1);

    ListNode* test2 = createList({2, 1, 3, 5, 6, 4, 7});
    cout << "Input:  [2, 1, 3, 5, 6, 4, 7]" << endl;
    cout << "Output: "; printList(sol.oddEvenList(test2));
    cout << "Expected: [2, 3, 6, 1, 5, 4, 7]\n" << endl;
    deleteList(test2);

    ListNode* test3 = nullptr;
    cout << "Input:  []" << endl;
    cout << "Output: "; printList(sol.oddEvenList(test3));
    cout << "Expected: []\n" << endl;

    ListNode* test4 = createList({1, 2});
    cout << "Input:  [1, 2]" << endl;
    cout << "Output: "; printList(sol.oddEvenList(test4));
    cout << "Expected: [1, 2]\n" << endl;
    deleteList(test4);

    return 0;
}