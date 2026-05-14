# 817 - Linked List Components

Solution for the "Linked List Components" LeetCode problem. This implementation focuses on optimizing lookup times and utilizing a state-machine approach to count contiguous blocks.

## Problem Description
You are given the `head` of a linked list containing unique integer values and an integer array `nums` that is a subset of the linked list values.
Return the number of connected components in `nums` where two values are connected if they appear consecutively in the linked list.

## Technical Analysis
This solution employs two major optimizations to ensure efficiency and code clarity:

1. **$O(1)$ Hash Set Lookups:** Scanning an array inside a linked list traversal would result in a quadratic time complexity of $O(N \cdot M)$. By pre-converting the `nums` vector into a `std::unordered_set`, the algorithm reduces the existence check (`numSet.count`) to an average $O(1)$ constant time.
2. **Rising Edge Detection (State Machine):** To count contiguous blocks without using nested loops, the algorithm tracks the historical state of traversal using two boolean flags (`flag1` for the previous node, `flag2` for the current node). A new component is only counted at the exact moment a transition from a non-subset node (or the start of the list) to a subset node occurs (`flag2 == true && flag1 == false`). 

- **Time Complexity:** $O(N + M)$ — Where $N$ is the length of the linked list and $M$ is the size of the `nums` array. Populating the hash set takes $O(M)$ time, and traversing the linked list takes $O(N)$ time.
- **Space Complexity:** $O(M)$ — Required to store the values of the `nums` array inside the `unordered_set` to achieve the constant-time lookup optimization.

## How to Build and Run
Ensure you have a C++ compiler installed.

1. **Compile the source:**
   ```bash
   g++ linkedListComponents.cpp -o linkedListComponents
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\linkedListComponents.exe

   # On Linux / macOS:
   ./linkedListComponents
   ```