# 03 - Longest Substring Without Repeating Characters

Solution for the "Longest Substring Without Repeating Characters" LeetCode problem, optimized for performance and rigorously tested against algorithmic edge cases.

## Problem Description
Given a string `s`, find the length of the **longest substring** without repeating characters.

## Technical Analysis
This solution employs an optimized **Sliding Window** technique combined with **Direct Addressing** (using a fixed array as a minimal, high-performance hash map).

- **Time Complexity:** $O(n)$ — The string is traversed exactly once by the right pointer `j`. When a duplicate is encountered, the left pointer `i` skips directly to the new valid boundary, bypassing unnecessary iterative step-by-step checks.
- **Space Complexity:** $O(1)$ — We allocate a fixed-size integer array of length 256 to map all possible ASCII characters. Since this memory footprint is strictly constant and does not scale with the length of the input string, the space complexity remains $O(1)$.

## Testing Strategy & Edge Cases
The `main` function is designed to validate the algorithm not just against standard inputs, but against critical edge cases that typically break naive implementations:

1. **The "Jump" Trap (`"dvdf"`):** Proves that the left boundary of the window does not simply reset or increment by one upon finding a duplicate, but correctly jumps to `last_seen[curr] + 1` (saving the valid `'v'` in the middle).
2. **Absolute Repetition (`"bbbbb"`):** Ensures the window size is evaluated correctly when the entire string is a single repeating character.
3. **Empty String (`""`):** Prevents memory access violations (Segmentation Faults) by gracefully handling length-zero inputs.
4. **Invisible Characters (`" "`):** Verifies that non-alphanumeric characters (like spaces) are correctly processed using their ASCII values.

## How to Build and Run
Ensure you have a C++ compiler installed (GCC/Clang/MSVC).

1. **Compile the source:**
   ```bash
   g++ longestSubstringWithoutRepeatingCharacters.cpp -o longestSubstringWithoutRepeatingCharacters
   ```
2. **Run the executable:**
   ```bash
   # On Windows:
   .\longestSubstringWithoutRepeatingCharacters.exe

   # On Linux / macOS:
   ./longestSubstringWithoutRepeatingCharacters
   ```