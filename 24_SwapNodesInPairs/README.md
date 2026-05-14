# 24 - Swap Nodes in Pairs

Solution for the "Swap Nodes in Pairs" LeetCode problem, featuring an in-place iterative algorithm with $O(1)$ auxiliary space and rigorous pointer rewiring.

## Problem Description
Given a linked list, swap every two adjacent nodes and return its head. The problem strictly forbids modifying the values inside the nodes; only the pointers themselves may be altered.

## Technical Analysis
This solution uses an **Iterative Pointer Manipulation** strategy anchored by a Dummy Node. 

- **Time Complexity:** $O(n)$ — We traverse the linked list exactly once, performing a constant number ($O(1)$) of pointer reassignments at each step.
- **Space Complexity:** $O(1)$ — The algorithm operates entirely in-place. Only a few auxiliary pointers (`dummy`, `prev`, `first`, `second`) are allocated on the stack, requiring strictly constant extra memory.

## Implementation Details & Edge Cases
1. **Dummy Node Injection:** A `dummy` node is locally allocated on the stack and points to the `head`. This unifies the logic, allowing the first pair of nodes to be swapped using the exact same code block as any other pair in the middle of the list.
2. **Atomic Rewiring:** The core of the algorithm manipulates three pointers simultaneously: `prev->next = second`, `first->next = second->next`, and `second->next = first`. This specific order prevents breaking the chain and losing the reference to the rest of the list.
3. **Odd-Length Safety:** The loop condition `while (prev->next != nullptr && prev->next->next != nullptr)` acts as a mathematical guard rail. If the list has an odd number of elements, the final single node is safely ignored and left attached to the tail.

## How to Build and Run
Ensure you have a C++ compiler installed (GCC/Clang/MSVC).

1. **Compile the source:**
   ```bash
   g++ swapNodesInPairs.cpp -o swapNodesInPairs
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\swapNodesInPairs.exe

   # On Linux / macOS:
   ./swapNodesInPairs
   ```