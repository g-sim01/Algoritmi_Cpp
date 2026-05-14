# 1721 - Swapping Nodes in a Linked List

Solution for the "Swapping Nodes in a Linked List" LeetCode problem. This algorithm employs an optimized, single-pass distance sliding window to identify symmetric nodes relative to the list's bounds.

## Problem Description
You are given the `head` of a linked list, and an integer `k`.
Return the head of the linked list after **swapping the values** of the $k^{th}$ node from the beginning and the $k^{th}$ node from the end (the list is 1-indexed).

## Technical Analysis
To solve this in a single traversal without prior knowledge of the total length of the list, this solution utilizes the **Fast & Slow Pointers** technique to establish a geometric gap.

- **Time Complexity:** $O(n)$ — The list is traversed exactly once. The `fast` pointer reaches the tail, directly triggering the end of the operation.
- **Space Complexity:** $O(1)$ — The algorithm strictly uses three auxiliary pointers (`slow`, `fast`, `swap`), requiring constant extra memory.

## Algorithmic Strategy
1. **Initial Offset:** The `fast` pointer is advanced $k-1$ times. It now rests on the target node from the left. A temporary pointer (`swap`) anchors this position.
2. **Geometric Sliding Window:** The `slow` pointer starts at the `head` while `fast` resumes from its $k^{th}$ position. Both advance at the exact same velocity. The mathematical consequence is that when `fast` hits the boundary (the last node), `slow` is trailing exactly by the distance $k$. Therefore, `slow` naturally lands on the $k^{th}$ node from the right.
3. **In-place Value Swap:** As permitted by the problem statement, the `.val` properties of the `swap` node and `slow` node are exchanged. This avoids the severe overhead and edge cases associated with rewiring actual pointer connections.

## How to Build and Run
Ensure you have a standard C++ compiler installed (e.g., GCC or Clang).

1. **Compile the code:**
   ```bash
   g++ swappingNodesInALinkedList.cpp -o swappingNodesInALinkedList
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\swappingNodesInALinkedList.exe

   # On Linux / macOS:
   ./swappingNodesInALinkedList
   ```