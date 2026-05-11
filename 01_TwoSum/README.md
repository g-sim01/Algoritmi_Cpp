# 01 - Two Sum

Optimized solution for the "Two Sum" problem (LeetCode).

## Problem Description
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

## Technical Analysis
This solution utilizes a **Hash Map** (`std::unordered_map`) to achieve high performance and avoid the $O(n^2)$ complexity of a nested loop approach.

- **Time Complexity:** $O(n)$ — We perform a single pass through the array. Hash map lookups and insertions have an amortized cost of $O(1)$.
- **Space Complexity:** $O(n)$ — In the worst-case scenario, we store all elements of the array in the map.

## How to Build and Run
Ensure you have a C++ compiler installed (GCC/Clang/MSVC).

1. **Compile the source:**
   ```bash
   g++ twoSum.cpp -o twoSum
   ```

2. **Run the executable:**
   ```bash
   twoSum.exe
   ```