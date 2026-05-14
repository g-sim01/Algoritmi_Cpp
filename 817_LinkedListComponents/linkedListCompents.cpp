#include <iostream>
#include <vector>
#include <unordered_set>

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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        bool flag1 = false;
        bool flag2 = false;
        int cont = 0;
        
        while (head != nullptr) {
            flag2 = numSet.count(head->val);
            
            if (flag2 == true && flag1 == false) {
                cont++;
            }
            
            flag1 = flag2;
            
            head = head->next;
        }
        
        return cont;
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
    
    ListNode* test1 = createList({0, 1, 2, 3});
    vector<int> nums1 = {0, 1, 3};
    cout << "Input:  Lista = [0, 1, 2, 3], nums = [0, 1, 3]" << endl;
    cout << "Output: " << sol.numComponents(test1, nums1) << " | Expected: 2\n" << endl;
    deleteList(test1);

    ListNode* test2 = createList({0, 1, 2, 3, 4});
    vector<int> nums2 = {0, 3, 1, 4};
    cout << "Input:  Lista = [0, 1, 2, 3, 4], nums = [0, 3, 1, 4]" << endl;
    cout << "Output: " << sol.numComponents(test2, nums2) << " | Expected: 2\n" << endl;
    deleteList(test2);

    ListNode* test3 = createList({1, 2, 3});
    vector<int> nums3 = {4, 5};
    cout << "Input:  Lista = [1, 2, 3], nums = [4, 5]" << endl;
    cout << "Output: " << sol.numComponents(test3, nums3) << " | Expected: 0\n" << endl;
    deleteList(test3);

    ListNode* test4 = createList({1, 2, 3});
    vector<int> nums4 = {1, 2, 3};
    cout << "Input:  Lista = [1, 2, 3], nums = [1, 2, 3]" << endl;
    cout << "Output: " << sol.numComponents(test4, nums4) << " | Expected: 1\n" << endl;
    deleteList(test4);

    return 0;
}