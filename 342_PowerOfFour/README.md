# 342 - Power of Four

This repository contains the most efficient solution for checking if an integer is a power of four, achieving a strictly constant time complexity.

## Problem Description
Given an integer `n`, return `true` if it is a power of four. Otherwise, return `false`.
An integer `n` is a power of four if there exists an integer `x` such that $n == 4^x$.

**Constraint:** Solve it in $O(1)$ time without using loops or recursion.

## Technical Analysis (The Mathematical Proof)

To determine if a number is a power of four in $O(1)$ time, the algorithm verifies three independent mathematical properties:

1.  **Positivity ($n > 0$):** Powers of four are always positive.
2.  **Power of Two Check (`(n & (n - 1)) == 0`):** Every power of four ($4^x$) is also a power of two ($2^{2x}$). In binary representation, a power of two is characterized by having exactly one bit set to `1`. Performing a bitwise AND between `n` and `n - 1` effectively clears the lowest set bit. If the result is `0`, it proves the number has only one bit set.
3.  **Modular Congruence (`(n - 1) % 3 == 0`):** This condition distinguishes powers of four from other powers of two (like $8, 32, 128$).
    -   Mathematically, $4 \equiv 1 \pmod 3$.
    -   Therefore, $4^k \equiv 1^k \equiv 1 \pmod 3$ for any $k \ge 0$.
    -   This implies that $4^k - 1$ is always divisible by $3$.
    -   Powers of two that are NOT powers of four (e.g., $2^1, 2^3, 2^5$) are congruent to $2 \pmod 3$, so $(n - 1) \% 3$ would result in $1$.

## How to Build and Run
Ensure you have a C++ compiler installed.

1. **Compile the source:**
   ```bash
   g++ powerOfFour.cpp -o powerOfFour
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\powerOfFour.exe

   # On Linux / macOS:
   ./powerOfFour
   ```