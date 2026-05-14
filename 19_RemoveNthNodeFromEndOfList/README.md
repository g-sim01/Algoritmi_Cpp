# 19 - Remove Nth Node From End of List

Solution for the "Remove Nth Node From End of List" LeetCode problem, implementing an optimized one-pass algorithm with strict C++ memory management.

## Problem Description
Given the `head` of a linked list, remove the $n^{th}$ node from the end of the list and return its head.
*Follow-up challenge:* Solve it in one pass.

## Technical Analysis
This solution utilizes the **Fast & Slow Pointers** technique to achieve the result in a single traversal (One-Pass).

- **Time Complexity:** $O(L)$ — Where $L$ is the total number of nodes in the linked list. The `fast` pointer traverses the list exactly once, making it the most optimal time complexity possible.
- **Space Complexity:** $O(1)$ — The algorithm strictly uses three auxiliary pointers (`dummy`, `slow`, `fast`), requiring constant extra space regardless of the list's size.

## Implementation Details & Edge Cases
This implementation focuses not only on algorithmic efficiency but also on robust software engineering practices specific to C++:

1. **The Dummy Node Strategy:** A `dummy` node is allocated locally on the Stack and points to the `head` of the list. This elegantly handles the critical edge case where the node to be removed is the very first node (e.g., list `[1, 2]`, $n = 2$). Without the dummy node, removing the head would require messy conditional logic or risk a segmentation fault.
2. **Strict Memory Management:** Unlike garbage-collected languages (Java/Python), C++ requires explicit memory deallocation. After the `slow` pointer bypasses the target node (`slow->next = slow->next->next`), the bypassed node is physically destroyed from the Heap using `delete` to prevent memory leaks.
3. **Pointer Spacing:** The `fast` pointer is advanced $n$ steps ahead of the `slow` pointer. When `fast` reaches the end of the list, `slow` is mathematically guaranteed to be positioned exactly *one node before* the target node that needs deletion.

## How to Build and Run
Ensure you have a C++ compiler installed (GCC/Clang/MSVC).

1. **Compile the source:**
   ```bash
   g++ removeNthNodeFromEndOfList.cpp -o removeNthNodeFromEndOfList
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\removeNthNodeFromEndOfList.exe

   # On Linux / macOS:
   ./removeNthNodeFromEndOfList
   ```