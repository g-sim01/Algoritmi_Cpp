# 32 - Longest Valid Parentheses

Solution for the "Longest Valid Parentheses" LeetCode problem (Hard). This implementation utilizes the highly optimized **Two-Pass (Bidirectional Counter)** approach, avoiding the memory overhead of Stacks or Dynamic Programming arrays.

## Technical Analysis
Finding the longest valid substring of parentheses normally requires keeping track of indices using a Stack, which costs $O(n)$ extra memory. This solution reduces the space requirement to strictly constant memory by utilizing two simple counters (`left` and `right`) and scanning the string twice.

- **Time Complexity:** $O(n)$ — The string is traversed exactly twice (once forward, once backward). $2n$ operations scale linearly to $O(n)$.
- **Space Complexity:** $O(1)$ — Only three integer variables are allocated (`left`, `right`, `max_len`), making this the most memory-efficient solution mathematically possible.

## Why Two Passes? (The Asymmetry Trap)
The core logic evaluates a valid sequence when `left == right`. 
If we encounter more closing parentheses than opening ones (`right > left`), the sequence is broken, and we reset the counters. 

However, a critical edge case arises with strings like `"(()"`. 
If we only traverse left-to-right, `left` will always remain greater than `right`. The counters will never equal each other, and `max_len` will incorrectly remain `0`. 

To solve this mathematically without a stack, we simply **reverse the traversal**. By traversing from right-to-left, the excess opening parenthesis acts as the sequence breaker (`left > right`), effectively resetting the counters and correctly identifying the `"()"` substring, returning the correct length of `2`.

## How to Build and Run
Ensure you have a C++ compiler installed.

1. **Compile the source:**
   ```bash
   g++ longestValidParentheses.cpp -o longestValidParentheses
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\longestValidParentheses.exe

   # On Linux / macOS:
   ./longestValidParentheses
   ```