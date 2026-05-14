# 09 - Palindrome Number

Solution for the "Palindrome Number" LeetCode problem, featuring an optimized, pure-math approach that avoids string conversion and inherently prevents integer overflow.

## Problem Description
Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise. 
*Follow-up challenge:* Solve it without converting the integer to a string.

## Technical Analysis
This solution employs a **Mathematical Half-Reversion** strategy. Instead of converting the integer to a string (which costs $O(n)$ space) or reverting the entire integer, it computes the reverse of only the *second half* of the digits and compares it with the remaining first half.

- **Time Complexity:** $O(\log_{10}(n))$ — The input number is divided by 10 in every iteration, meaning the loop runs for exactly half the number of digits in `x`.
- **Space Complexity:** $O(1)$ — The algorithm strictly uses a few primitive integer variables, requiring strictly constant auxiliary space.

## Testing Strategy & Edge Cases
The `main` executable includes a robust testing suite designed to validate the mathematical boundaries and hardware limitations of the environment:

1. **Integer Overflow Prevention (`2147447412`):** This is the crucial architectural test. Reverting an integer close to the 32-bit limit (`2,147,483,647`) would cause a fatal overflow. By halting the loop at the halfway point (`x > revertedNumber`), the algorithm safely operates well below the hardware memory limit.
2. **Negative Numbers (`-121`):** Instantly caught and rejected in $O(1)$ time, as the trailing minus sign makes palindromic symmetry mathematically impossible.
3. **Trailing Zeros (`10`):** Handled via a fast-fail condition. A valid integer (other than `0` itself) never starts with a `0`, therefore any number ending in `0` cannot be a palindrome.
4. **Odd vs. Even Digit Counts (`1221` vs. `12321`):** Validates the dual return condition `x == revertedNumber || x == revertedNumber / 10` to successfully ignore the middle digit in odd-length palindromes.

## How to Build and Run
Ensure you have a C++ compiler installed (GCC/Clang/MSVC).

1. **Compile the source:**
   ```bash
   g++ palindromeNumber.cpp -o palindromeNumber
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\palindromeNumber.exe

   # On Linux / macOS:
   ./palindromeNumber
   ```