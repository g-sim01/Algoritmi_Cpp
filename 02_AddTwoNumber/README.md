# 02 - Add Two Numbers

Solution for the "Add Two Numbers" LeetCode problem.

## Problem Description
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

## Technical Analysis
This solution uses a **Single-Pass Iteration** approach. It traverses both linked lists simultaneously, simulating traditional column addition digit by digit, and maintains a variable for the carry-over.

- **Time Complexity:** $O(\max(m, n))$ — Where $m$ and $n$ represent the lengths of `l1` and `l2` respectively. The algorithm iterates at most $\max(m, n)$ times, plus a potential extra iteration if there is a final carry.
- **Space Complexity:** $O(1)$ (Auxiliary) — The algorithm only allocates a few scalar variables (pointers, `sum`, and `report`). The memory allocated for the new `ListNode` elements constitutes the required output itself, and is typically excluded from auxiliary space analysis.

## Implementation Details
- **Dummy Node Strategy:** A `dummyHead` pointer initialized to `new ListNode(0)` is used to elegantly handle the edge case of the first node insertion without needing separate conditional logic.
- **Carry (Report):** Evaluated strictly outside the `while` loop scope to preserve the mathematical state between positional calculations (units, tens, hundreds, etc.).

## How to Build and Run (Local Testing)
Unlike the LeetCode environment, running this locally requires the manual definition of the `ListNode` struct and a `main` entry point with helper functions to generate the linked lists.

Ensure you have a C++ compiler installed (GCC/Clang/MSVC).

1. **Compile the source:**
   ```bash
   g++ addTwoNumbers.cpp -o addTwoNumbers
   ```
2. **Run the executable:**
   ```bash
   addTwoNumbers.exe
   ```