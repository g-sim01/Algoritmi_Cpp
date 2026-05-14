# 328 - Odd Even Linked List

Solution for the "Odd Even Linked List" LeetCode problem, implementing an optimal, in-place algorithmic strategy that strictly adheres to structural memory constraints.

## Problem Description
Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The relative order inside both the even and odd groups must remain as it was in the input.

**Constraints:** The algorithm must execute in $O(1)$ extra space complexity and $O(n)$ time complexity.

## Technical Analysis
To solve this problem without allocating additional memory for new arrays or lists, this solution utilizes a **Parallel Pointer Manipulation** strategy (often visualized as unzipping a zipper into two tracks).

- **Time Complexity:** $O(n)$ — The algorithm traverses the linked list exactly once. Each iteration of the `while` loop processes two nodes simultaneously, making it highly efficient.
- **Space Complexity:** $O(1)$ — Only three local pointers (`curr`, `prox`, `flag`) are allocated on the stack. No new structural nodes are created in the Heap, meaning the memory footprint remains absolutely constant regardless of list size.

## Implementation Architecture
1. **The Fast-Fail Guard:** The initial check `if (head == nullptr || head->next == nullptr)` immediately returns safely for lists of length $0$ or $1$, bypassing unnecessary initialization and preventing segmentation faults.
2. **The "Two Tracks" Logic:**
   - `curr` (odd) jumps to the next odd node: `curr->next = prox->next`.
   - `prox` (even) jumps to the next even node: `prox->next = curr->next->next`.
3. **The Anchor (`flag`):** As the list is split into two logical sub-lists within the same memory space, the head of the even list is lost if not saved. The `flag` pointer serves as the anchor, allowing the algorithm to seamlessly append the even track to the tail of the odd track (`curr->next = flag`) before returning the fully reordered sequence.

## How to Build and Run
Ensure you have a C++ compiler installed.

1. **Compile the source:**
   ```bash
   g++ oddEvenLinkedList.cpp -o oddEvenLinkedList
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\oddEvenLinkedList.exe

   # On Linux / macOS:
   ./oddEvenLinkedList
   ```